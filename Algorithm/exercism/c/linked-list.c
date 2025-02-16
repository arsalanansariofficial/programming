#include <stdlib.h>
#include <stddef.h>

typedef int ll_data_t;

typedef struct list_node
{
  ll_data_t data;
  struct list_node *prev, *next;
} node_t;

typedef struct list
{
  ll_data_t length;
  node_t *head, *tail;
} list_t;

struct list *list_create(void);
size_t list_count(const struct list *list);

void list_push(struct list *list, ll_data_t item_data);
ll_data_t list_pop(struct list *list);

void list_unshift(struct list *list, ll_data_t item_data);
ll_data_t list_shift(struct list *list);

void list_delete(struct list *list, ll_data_t data);

void list_destroy(struct list *list);

struct list *list_create(void)
{
  list_t *new_list = malloc(sizeof(list_t));

  if (!new_list)
  {
    return NULL;
  }

  new_list->length = 0;
  new_list->head = NULL;
  new_list->tail = NULL;

  return new_list;
}

size_t list_count(const struct list *list)
{
  return list->length;
}

static node_t *create_node(ll_data_t data, struct list *list)
{
  node_t *new_node = malloc(sizeof(node_t));

  if (!new_node)
  {
    return NULL;
  }

  list->length++;
  new_node->data = data;

  if (list->head)
  {
    new_node->prev = list->tail;
    new_node->next = list->head;
    list->tail->next = new_node;
    list->head->prev = new_node;
    return new_node;
  }

  new_node->prev = new_node;
  new_node->next = new_node;
  list->head = new_node;
  list->tail = new_node;

  return new_node;
}

static ll_data_t destroy_node(node_t *node, struct list *list)
{
  ll_data_t data = node->data;

  node->prev->next = node->next;
  node->next->prev = node->prev;

  if (node == list->head)
  {
    list->head = node->next;
  }

  if (node == list->tail)
  {
    list->tail = node->prev;
  }

  free(node);
  node = NULL;
  list->length--;

  if (list->length == 0)
  {
    list->head = NULL;
    list->tail = NULL;
  }

  return data;
}

void list_push(struct list *list, ll_data_t item_data)
{
  list->tail = create_node(item_data, list);
}

ll_data_t list_pop(struct list *list)
{
  return destroy_node(list->tail, list);
}

void list_unshift(struct list *list, ll_data_t item_data)
{
  list->head = create_node(item_data, list);
}

ll_data_t list_shift(struct list *list)
{
  return destroy_node(list->head, list);
}

void list_delete(struct list *list, ll_data_t data)
{
  node_t *node = list->head;

  while (node)
  {
    if (node->data == data)
    {
      destroy_node(node, list);
      break;
    }

    if (node->next == list->head)
      break;

    node = node->next;
  }
}

void list_destroy(struct list *list)
{
  while (list->length > 0)
  {
    list_pop(list);
  }

  free(list);
  list = NULL;
}