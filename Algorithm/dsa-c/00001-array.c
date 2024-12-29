#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  int size;
  int capacity;
  int *data;
} Vector;

// Prototype to use function before initialization
bool is_empty(Vector *vector);

void resize(Vector *vector, int new_capacity);

void check_empty(Vector *vector)
{
  if (is_empty(vector))
  {
    fprintf(stderr, "The array is empty");
    exit(EXIT_FAILURE);
  }
}

void check_index(Vector *vector, int index)
{
  if (index < 0 || index > vector->size)
  {
    fprintf(stderr, "Index out of bound");
    exit(EXIT_FAILURE);
  }
}

void increase_capacity(Vector *vector)
{
  if (vector->size == vector->capacity)
  {
    resize(vector, vector->capacity * 2);
  }
}

void reduce_capacity(Vector *vector)
{
  if (vector->size > 0 && vector->size == vector->capacity / 4)
  {
    vector->capacity == vector->capacity / 2;
  }
}

Vector *create_vector(int initial_capacity)
{
  Vector *vector = (Vector *)malloc(sizeof(Vector));

  vector->size = 0;
  vector->capacity = initial_capacity > 16 ? initial_capacity : 16;
  vector->data = (int *)calloc(vector->capacity, sizeof(int));

  return vector;
}

int size(Vector *vector)
{
  return vector->size;
}

int capacity(Vector *vector)
{
  return vector->capacity;
}

bool is_empty(Vector *vector)
{
  return vector->size == 0;
}

int at(Vector *vector, int index)
{
  check_index(vector, index);

  // return *(vector->data + index); // Using pointer
  return vector->data[index];
}

void push(Vector *vector, int element)
{
  increase_capacity(vector);

  // *(vector->data + vector->size++) = element; // Using pointer
  vector->data[vector->size++] = element;
}

void insert(Vector *vector, int index, int element)
{
  check_index(vector, index);
  increase_capacity(vector);

  for (int i = vector->size; i > index; i--)
  {
    // *(vector->data + i) = *(vector->data + i - 1); Using pointer
    vector->data[i] = vector->data[i - 1];
  }

  // *(vector->data + index) = item; // Using pointer
  vector->data[index] = element;
  vector->size++;
}

void prepend(Vector *vector, int element)
{
  insert(vector, 0, element);
}

int pop(Vector *vector)
{
  check_empty(vector);
  int item = vector->data[vector->size - 1];

  vector->size--;
  reduce_capacity(vector);

  return item;
}

void delete(Vector *vector, int index)
{
  check_index(vector, index);
  check_empty(vector);

  for (int i = index; i < vector->size - 1; i++)
  {
    vector->data[i] = vector->data[i + 1];
  }

  vector->size--;
  reduce_capacity(vector);
}

void remove_item(Vector *vector, int element)
{
  for (int i = 0; i < vector->size; i++)
  {
    if (element == vector->data[i])
    {
      delete (vector, i);
      i--;
    }
  }
}

int find(Vector *vector, int element)
{
  check_empty(vector);

  for (int i = 0; i < vector->size; i++)
  {
    if (element == vector->data[i])
    {
      return i;
    }
  }

  return -1;
}

void resize(Vector *vector, int new_capacity)
{
  vector->data = realloc(vector->data, new_capacity);
  vector->capacity = new_capacity;
}

int main()
{
  Vector *vector = create_vector(16);

  printf("The size of vector is %i\n", size(vector));
  printf("The capacity of vector is %i\n", capacity(vector));
  printf("Status of vector is %i\n", is_empty(vector));

  push(vector, 1);
  push(vector, 2);
  push(vector, 3);
  push(vector, 3);
  push(vector, 3);

  prepend(vector, 0);
  insert(vector, 1, 4);

  pop(vector);
  pop(vector);
  pop(vector);
  delete (vector, 1);
  remove_item(vector, 3);

  pop(vector);
  pop(vector);
  delete (vector, 1);

  for (int i = 0; i < vector->size; i++)
  {
    if (i == 0)
    {
      printf("Array elements: ");
    }

    printf("%i ", at(vector, i));

    if (i + 1 == vector->size)
    {
      printf("\n");
    }
  }

  printf("Position of 3 is %i\n", find(vector, 3));
  printf("Position of 1 is %i\n", find(vector, 1));
}
