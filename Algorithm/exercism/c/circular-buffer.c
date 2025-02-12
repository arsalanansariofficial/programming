#include <errno.h>
#include <stdlib.h>
#include <stdint.h>

#define ENODATA 61
#define ENOBUFS 105

typedef int16_t buffer_value_t;

typedef struct
{
  int size;
  int index;
  int capacity;
  buffer_value_t buffer[];
} circular_buffer_t;

void clear_buffer(circular_buffer_t *buffer);
void delete_buffer(circular_buffer_t *buffer);
circular_buffer_t *new_circular_buffer(unsigned int capacity);

int write(circular_buffer_t *buffer, buffer_value_t value);
int overwrite(circular_buffer_t *buffer, buffer_value_t value);
int read(circular_buffer_t *buffer, buffer_value_t *read_value);

void clear_buffer(circular_buffer_t *buffer)
{
  buffer->size = 0;
}

void delete_buffer(circular_buffer_t *buffer)
{
  free(buffer);
}

circular_buffer_t *new_circular_buffer(unsigned int capacity)
{
  circular_buffer_t *buffer = calloc(1, sizeof(circular_buffer_t) + capacity * sizeof(buffer_value_t));
  buffer->capacity = capacity;
  return buffer;
}

int write(circular_buffer_t *buffer, buffer_value_t value)
{
  if (buffer->size >= buffer->capacity)
  {
    errno = ENOBUFS;
    return EXIT_FAILURE;
  }

  buffer->buffer[(buffer->index + buffer->size++) % buffer->capacity] = value;
  return EXIT_SUCCESS;
}

int overwrite(circular_buffer_t *buffer, buffer_value_t value)
{
  if (buffer->size >= buffer->capacity)
  {
    buffer->index++;
    buffer->size--;
  }

  return write(buffer, value);
}

int read(circular_buffer_t *buffer, buffer_value_t *read_value)
{
  if (!buffer->size)
  {
    errno = ENODATA;
    return EXIT_FAILURE;
  }

  *read_value = buffer->buffer[buffer->index++ % buffer->capacity];
  buffer->size--;

  return EXIT_SUCCESS;
}
