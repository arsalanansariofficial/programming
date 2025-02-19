#include <stdlib.h>

#define LIMIT 32

typedef void (*callback)(void *, int);
typedef int callback_id;
typedef int (*compute1)(int);
typedef int (*compute2)(int, int);

struct reactor
{
  struct cell *cells[LIMIT];
  int length;
};

struct cell
{
  callback callbacks[LIMIT];
  void *args[LIMIT];
  struct cell *feed1, *feed2;
  compute1 process1;
  compute2 process2;
  int value, num_callbacks;
};

struct reactor *create_reactor(void);
void destroy_reactor(struct reactor *);

struct cell *create_input_cell(struct reactor *, int initial_value);
struct cell *create_compute1_cell(struct reactor *, struct cell *, compute1);
struct cell *create_compute2_cell(struct reactor *, struct cell *, struct cell *, compute2);

int get_cell_value(struct cell *);
void set_cell_value(struct cell *, int new_value);

callback_id add_callback(struct cell *, void *, callback);
void remove_callback(struct cell *, callback_id);

static void update(void *cell, int n)
{
  (void)n;
  struct cell *c = cell;
  set_cell_value(c, get_cell_value(c));
}

struct reactor *create_reactor(void)
{
  return (struct reactor *)calloc(1, sizeof(struct reactor));
}

void destroy_reactor(struct reactor *r)
{
  while (r->length--)
    free(r->cells[r->length]);
}

struct cell *create_input_cell(struct reactor *r, int initial_value)
{
  struct cell *c = (struct cell *)calloc(1, sizeof(struct cell));

  if (c)
  {
    c->value = initial_value;
    r->cells[r->length++] = c;
  }

  return c;
}

struct cell *create_compute1_cell(struct reactor *r, struct cell *feed1, compute1 f)
{
  struct cell *c = (struct cell *)calloc(1, sizeof(struct cell));

  if (c)
  {
    c->feed1 = feed1;
    c->process1 = f;
    c->value = get_cell_value(c);
    add_callback(feed1, c, update);
    r->cells[r->length++] = c;
  }

  return c;
}

struct cell *create_compute2_cell(struct reactor *r, struct cell *feed1, struct cell *feed2, compute2 f)
{
  struct cell *c = (struct cell *)calloc(1, sizeof(struct cell));

  if (c)
  {
    c->feed1 = feed1;
    c->feed2 = feed2;
    c->process2 = f;
    c->value = get_cell_value(c);
    add_callback(feed1, c, update);
    add_callback(feed2, c, update);
    r->cells[r->length++] = c;
  }

  return c;
}

int get_cell_value(struct cell *c)
{
  if (!c->feed1)
  {
    return c->value;
  }

  return c->feed2 ? c->process2(get_cell_value(c->feed1), get_cell_value(c->feed2)) : c->process1(get_cell_value(c->feed1));
}

void set_cell_value(struct cell *c, int new_value)
{
  if (c->value != new_value)
  {
    c->value = new_value;

    for (int i = 0; i < c->num_callbacks; i++)
    {
      if (c->callbacks[i])
      {
        c->callbacks[i](c->args[i], c->value);
      }
    }
  }
}

callback_id add_callback(struct cell *c, void *arg, callback f)
{
  c->callbacks[c->num_callbacks] = f;
  c->args[c->num_callbacks] = arg;
  return c->num_callbacks++;
}

void remove_callback(struct cell *c, callback_id id)
{
  c->callbacks[id] = NULL;
}
