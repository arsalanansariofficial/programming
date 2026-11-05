#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

void swap_elements(int *a, int *b);
void print_array(int array[], int length);

void bubble_sort_array(int array[], int length);
void selection_sort_array(int array[], int length);

void insertion_sort_array(int array[], int length);

void heapify(int array[], int length, int index);
void heap_sort_array(int array[], int length);

void merge(int array[], int left, int mid, int right);
void merge_sort_array(int array[], int left, int right);

int partition(int arrray[], int left, int right);
void quick_sort(int array[], int left, int right);

Node *create_node(int value);
Node *create_linked_list(int array[], int length);
void print_linked_list(Node *head);

Node *split_linked_list(Node *head);
Node *merge_linked_lists(Node *first, Node *second);
Node *merge_sort_linked_list(Node *head);

void swap_elements(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void print_array(int array[], int length)
{
  for (int i = 0; i < length; i++)
  {
    if (!i)
    {
      printf("Array: [%i, ", array[i]);
      continue;
    }

    if (i + 1 == length)
    {
      printf("%i]\n", array[i]);
      continue;
    }

    printf("%i, ", array[i]);
  }
}

void bubble_sort_array(int array[], int length)
{
  for (int i = 0; i < length; i++)
  {
    for (int j = 1; j < length - i; j++)
    {
      if (array[j - 1] > array[j])
      {
        swap_elements(&array[j - 1], &array[j]);
      }
    }
  }
}

void selection_sort_array(int array[], int length)
{
  for (int i = 0; i < length; i++)
  {
    int max = 0;
    int end = length - i - 1;

    for (int j = 1; j < length - i; j++)
    {
      if (array[j] > array[max])
      {
        max = j;
      }
    }

    swap_elements(&array[max], &array[end]);
  }
}

void insertion_sort_array(int array[], int length)
{
  for (int i = 1; i < length; i++)
  {
    int j = i;

    while (j > 0 && array[j - 1] > array[j])
    {
      swap_elements(&array[j - 1], &array[j]);
      j--;
    }
  }
}

void heapify(int array[], int length, int index)
{
  int parent = index;
  int left = 2 * parent + 1;
  int right = 2 * parent + 2;

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

void heap_sort_array(int array[], int length)
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

void merge(int array[], int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int left_array[n1], right_array[n2];

  for (int i = 0; i < n1; i++)
  {
    left_array[i] = array[left + i];
  }

  for (int j = 0; j < n2; j++)
  {
    right_array[j] = array[mid + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = left;

  while (i < n1 && j < n2)
  {
    if (left_array[i] <= right_array[j])
    {
      array[k++] = left_array[i++];
      continue;
    }

    array[k++] = right_array[j++];
  }

  while (i < n1)
  {
    array[k++] = left_array[i++];
  }

  while (j < n2)
  {
    array[k++] = right_array[j++];
  }
}

void merge_sort_array(int array[], int left, int right)
{
  if (right <= left)
  {
    return;
  }

  int mid = left + (right - left) / 2;

  merge_sort_array(array, left, mid);
  merge_sort_array(array, mid + 1, right);

  merge(array, left, mid, right);
}

int partition(int arrray[], int left, int right)
{
  int i = left - 1;
  int pivot = arrray[right];

  for (int j = left; j <= right; j++)
  {
    if (arrray[j] < pivot)
    {
      swap_elements(&arrray[++i], &arrray[j]);
    }
  }

  swap_elements(&arrray[++i], &arrray[right]);
  return i;
}

void quick_sort(int array[], int left, int right)
{
  if (right <= left)
  {
    return;
  }

  int pivot = partition(array, left, right);

  quick_sort(array, left, pivot - 1);
  quick_sort(array, pivot + 1, right);
}

Node *create_node(int data)
{
  Node *head = malloc(sizeof(Node));
  head->data = data;
  head->next = NULL;
  return head;
}

Node *create_linked_list(int array[], int length)
{
  Node *head = NULL;
  Node *tail = NULL;

  for (int i = 0; i < length; i++)
  {
    if (!head)
    {
      head = create_node(array[i]);
      tail = head;
      continue;
    }

    tail->next = create_node(array[i]);
    tail = tail->next;
  }

  return head;
}

void print_linked_list(Node *head)
{
  printf("Linked List: ");

  while (head)
  {
    switch (!!head->next)
    {
    case 1:
      printf("%i --> ", head->data);
      break;

    default:
      printf("%i\n", head->data);
    }

    head = head->next;
  }
}

Node *split_linked_list(Node *head)
{
  Node *fast = head;
  Node *slow = head;
  Node *temp = NULL;

  while (fast && fast->next)
  {
    fast = fast->next->next;

    if (fast)
    {
      slow = slow->next;
    }
  }

  temp = slow->next;
  slow->next = NULL;

  return temp;
}

Node *merge_linked_lists(Node *first, Node *second)
{
  if (!first)
  {
    return second;
  }

  if (!second)
  {
    return first;
  }

  if (first->data < second->data)
  {
    first->next = merge_linked_lists(first->next, second);
    return first;
  }

  second->next = merge_linked_lists(first, second->next);
  return second;
}

Node *merge_sort_linked_list(Node *head)
{
  if (!head || !head->next)
  {
    return head;
  }

  Node *second = split_linked_list(head);

  head = merge_sort_linked_list(head);
  second = merge_sort_linked_list(second);

  return merge_linked_lists(head, second);
}

int main()
{
  int array[] = {8, 2, 5, 3, 9, 4, 7, 6, 1};

  bubble_sort_array(array, 9);
  print_array(array, 9);

  selection_sort_array(array, 9);
  print_array(array, 9);

  insertion_sort_array(array, 9);
  print_array(array, 9);

  heap_sort_array(array, 9);
  print_array(array, 9);

  merge_sort_array(array, 0, 8);
  print_array(array, 9);

  quick_sort(array, 0, 8);
  print_array(array, 9);

  Node *head = merge_sort_linked_list(create_linked_list(array, 9));
  print_linked_list(head);
}