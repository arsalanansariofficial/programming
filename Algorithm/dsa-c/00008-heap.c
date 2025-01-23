#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
  int *data;
  int length;
  int capacity;
} Heap;

void print_heap(Heap *heap);
void print_array(int array[], int length);
void insert(Heap *heap, int element);

int get_max(Heap *heap);
int get_size(Heap *heap);
int is_empty(Heap *heap);

int extract_max(Heap *heap);
void heap_sort(int array[], int length);
int remove_at(Heap *heap, int index);

void swap_elements(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

Heap *create_heap(int elements[], int length)
{
  Heap *heap = malloc(sizeof(Heap));

  heap->length = 0;
  heap->capacity = length;
  heap->data = calloc(length, sizeof(int));

  for (int i = 0; i < length; i++)
  {
    insert(heap, elements[i]);
  }

  return heap;
}

void print_heap(Heap *heap)
{
  if (!heap->length)
  {
    printf("Heap is empty\n");
    return;
  }

  printf("Heap: ");

  for (int i = 0; i < heap->length; i++)
  {
    printf("%i ", heap->data[i]);
  }

  printf("\n");
}

void print_array(int array[], int length)
{
  if (!length)
  {
    printf("Array is empty\n");
    return;
  }

  printf("Array: ");

  for (int i = 0; i < length; i++)
  {
    printf("%i ", array[i]);
  }

  printf("\n");
}

void insert(Heap *heap, int element)
{
  if (heap->length > heap->capacity)
  {
    printf("Heap is Full\n");
    return;
  }

  heap->length++;
  int index = heap->length - 1;
  int parent = (index - 1) / 2;

  heap->data[index] = element;

  while (heap->data[index] > heap->data[parent] && index > 0)
  {
    swap_elements(&heap->data[index], &heap->data[parent]);
    index = parent;
    parent = (index - 1) / 2;
  }
}

int get_max(Heap *heap)
{
  int max = heap->data[0];
  printf("Max: %i\n", max);
  return max;
}

int get_size(Heap *heap)
{
  printf("Size: %i\n", heap->length);
  return heap->length;
}

int is_empty(Heap *heap)
{
  printf("Empty: %s\n", !heap->length ? "True" : "False");
  return !heap->length;
}

int extract_max(Heap *heap)
{
  if (!heap->length)
  {
    printf("Heap is empty\n");
    return -1;
  }

  int index = 0;
  int element = heap->data[index];

  heap->data[index] = heap->data[heap->length - 1];
  heap->length--;

  while (index <= (heap->length / 2) - 1)
  {
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (heap->data[index] > heap->data[left] && heap->data[index] > heap->data[right])
    {
      break;
    }

    if (heap->data[left] > heap->data[right])
    {
      swap_elements(&heap->data[index], &heap->data[left]);
      index = left;
      continue;
    }

    swap_elements(&heap->data[index], &heap->data[right]);
    index = right;
  }

  return element;
}

int remove_at(Heap *heap, int index)
{
  if (index > heap->length)
  {
    printf("Index out of bound\n");
    return -1;
  }

  swap_elements(&heap->data[0], &heap->data[index]);
  int element = extract_max(heap);

  printf("Removed at %i: %i\n", index, element);
  return element;
}

void heapify(int array[], int length, int index)
{
  int parent = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < length && array[left] > array[parent])
  {
    parent = left;
  }

  if (right < length && array[right] > array[parent])
  {
    parent = right;
  }

  if (parent != index)
  {
    swap_elements(&array[index], &array[parent]);
    heapify(array, length, parent);
  }
}

void heap_sort(int array[], int length)
{
  for (int i = length / 2 - 1; i >= 0; i--)
  {
    heapify(array, length, i);
  }

  for (int i = length - 1; i > 0; i--)
  {
    swap_elements(&array[0], &array[i]);
    heapify(array, i, 0);
  }
}

int main()
{
  int array[] = {9, 8, 7, 6, 5};
  int elements[] = {1, 2, 3, 4, 5};
  Heap *heap = create_heap(elements, 5);

  get_size(heap);
  is_empty(heap);

  get_max(heap);
  print_heap(heap);

  printf("Max (Removed): %i\n", extract_max(heap));
  print_heap(heap);

  remove_at(heap, 2);
  print_heap(heap);

  heap_sort(array, 5);
  print_array(array, 5);
}