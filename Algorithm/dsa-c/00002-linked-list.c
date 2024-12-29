#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *create_node(int data);
void create_list(Node **head, int *nums, int len);
void get_tail(Node *head, Node **tail);
void print_list(Node *head);

int size(Node *head);
bool is_empty(Node *head);
int value_at(Node *head, int index);
void push_front(Node **head, int element);
int pop_front(Node **head);
void push_back(Node **head, int element);
int pop_back(Node **head);
int front(Node *head);
int back(Node *head);
void insert(Node **head, int index, int element);
void erase(Node **head, int index);
int value_n_from_end(Node *head, int n);
void reverse(Node **head);

void remove_element(Node **head, int element);

Node *create_node(int data)
{
  Node *new_node = (Node *)malloc(sizeof(Node));

  if (new_node == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void create_list(Node **head, int *nums, int len)
{
  for (int i = 0; i < len; i++)
  {
    push_back(head, nums[i]);
  }
}

void get_tail(Node *head, Node **tail)
{
  Node *current = head;

  if (!current)
  {
    *tail = NULL;
  }

  while (current->next)
  {
    current = current->next;
  }

  *tail = current;
}

void print_list(Node *head)
{
  while (head)
  {
    if (head->next)
    {
      printf("%i --> ", head->data);
    }
    else
    {
      printf("%i\n", head->data);
    }

    head = head->next;
  }
}

int size(Node *head)
{
  int length = 0;

  while (head)
  {
    length++;
    head = head->next;
  }

  return length;
}

bool is_empty(Node *head)
{
  return !head;
}

int value_at(Node *head, int index)
{
  if (index < 0 || index > size(head))
  {
    return -1;
  }

  int count = 0;

  while (head)
  {
    if (count == index)
    {
      return head->data;
    }

    head = head->next;
    count++;
  }
}

void push_front(Node **head, int element)
{
  Node *new_node = create_node(element);
  new_node->next = *head;
  *head = new_node;
}

int pop_front(Node **head)
{
  Node *current = *head;

  if (!current)
  {
    return -1;
  }

  int element = current->data;
  *head = current->next;

  return element;
}

void push_back(Node **head, int element)
{
  Node *current = *head;
  Node *new_node = create_node(element);

  if (!current)
  {
    *head = new_node;
  }
  else
  {
    Node *tail = NULL;
    get_tail(*head, &tail);
    tail->next = new_node;
  }
}

int pop_back(Node **head)
{
  Node *prev = NULL;
  Node *current = *head;

  if (!current)
  {
    return -1;
  }

  while (current->next)
  {
    prev = current;
    current = current->next;
  }

  int element = current->data;

  if (!prev)
  {
    *head = NULL;
  }
  else
  {
    prev->next = NULL;
  }

  free(current);
  return element;
}

int front(Node *head)
{
  return head ? head->data : -1;
}

int back(Node *head)
{
  Node *tail = NULL;
  get_tail(head, &tail);
  return tail ? tail->data : -1;
}

void insert(Node **head, int index, int data)
{
  if (index < 0)
  {
    fprintf(stderr, "Invalid index\n");
    return;
  }

  Node *new_node = create_node(data);

  if (index == 0)
  {
    new_node->next = *head;
    *head = new_node;
    return;
  }

  Node *current = *head;

  for (int i = 0; i < index - 1; i++)
  {
    if (!current)
    {
      fprintf(stderr, "Index out of bounds\n");
      free(new_node);
      return;
    }
    current = current->next;
  }

  if (!current)
  {
    fprintf(stderr, "Index out of bounds\n");
    free(new_node);
    return;
  }

  new_node->next = current->next;
  current->next = new_node;
}

void erase(Node **head, int index)
{
  Node *prev = NULL;
  Node *current = *head;

  if (index < 0 || !current)
  {
    fprintf(stderr, "Invalid index or empty list\n");
    return;
  }

  // If the node to be deleted is the head node
  if (index == 0)
  {
    *head = current->next;
    free(current);
    return;
  }

  // Find the node just before the one to be deleted
  for (int i = 0; i < index; i++)
  {
    if (!current)
    {
      fprintf(stderr, "Index out of bounds\n");
      return;
    }
    prev = current;
    current = current->next;
  }

  if (!current)
  {
    fprintf(stderr, "Index out of bounds\n");
    return;
  }

  prev->next = current->next;
  free(current);
}

int value_n_from_end(Node *head, int index)
{
  if (!head || index < 0)
  {
    fprintf(stderr, "Invalid input\n");
    exit(EXIT_FAILURE);
  }

  Node *ref_ptr = head;
  Node *main_ptr = head;

  // Move ref_ptr n nodes ahead
  for (int i = 0; i < index; i++)
  {
    if (!ref_ptr)
    {
      fprintf(stderr, "Index out of bounds\n");
      exit(EXIT_FAILURE);
    }
    ref_ptr = ref_ptr->next;
  }

  // Move both pointers until ref_ptr reaches the end
  while (ref_ptr->next)
  {
    main_ptr = main_ptr->next;
    ref_ptr = ref_ptr->next;
  }

  return main_ptr->data;
}

void reverse(Node **head)
{
  Node *current = *head;
  Node *prev = NULL;
  Node *next = NULL;

  while (current)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  *head = prev;
}

void remove_element(Node **head, int element)
{
  int index = -1;
  Node *current = *head;

  while (current)
  {
    index++;

    if (current->data == element)
    {
      erase(head, index);
      free(current);
      return;
    }

    current = current->next;
  }
}

int main()
{
  Node *head = NULL;
  int nums[] = {1, 2, 3};

  create_list(&head, nums, 3);

  printf("Size of list %i\n", size(head));
  printf("Is list empty %i\n", is_empty(head));
  printf("Element at index 2 --> %i\n", value_at(head, 2));

  printf("Current List ");
  print_list(head);

  printf("Add 0 at front ");
  push_front(&head, 0);
  print_list(head);

  printf("Delete 0 at front ");
  pop_front(&head);
  print_list(head);

  printf("Add 4 at the end ");
  push_back(&head, 4);
  print_list(head);

  printf("Delete 4 at the end ");
  pop_back(&head);
  print_list(head);

  printf("Element at front --> %i\n", front(head));
  printf("Element at back --> %i\n", back(head));

  printf("Insert element at index 1 ");
  insert(&head, 1, 0);
  print_list(head);

  printf("Delete element at index 1 ");
  erase(&head, 1);
  print_list(head);

  printf("Element at index 2 from the last --> %i\n", value_n_from_end(head, 2));

  printf("After reversing the list ");
  reverse(&head);
  print_list(head);

  printf("Remove 3 from the list ");
  remove_element(&head, 3);
  print_list(head);
}
