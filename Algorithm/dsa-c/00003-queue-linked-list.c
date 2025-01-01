#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int dequeue();
bool is_empty();
void enqueue(int value);

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

typedef struct Queue
{
  Node *head;
  Node *tail;
} Queue;

Queue *queue = NULL;

void print_list(Node *head)
{
  if (is_empty())
  {
    printf("Queue is is_empty\n");
    return;
  }

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

bool is_empty()
{
  return !queue->head;
}

void enqueue(int value)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->data = value;
  new_node->next = NULL;

  if (!queue->head)
  {
    queue->head = new_node;
    queue->tail = new_node;
    return;
  }

  queue->tail->next = new_node;
  queue->tail = queue->tail->next;
}

int dequeue()
{
  if (is_empty())
  {
    return -1;
  }

  Node *current = queue->head;
  int element = current->data;

  queue->head = queue->head->next;
  free(current);

  return element;
}

int main()
{
  queue = malloc(sizeof(Queue));
  queue->head = NULL;
  queue->tail = NULL;

  enqueue(1);
  printf("Enqueue 1 ");
  print_list(queue->head);

  enqueue(2);
  printf("Enqueue 2 ");
  print_list(queue->head);

  enqueue(3);
  printf("Enqueue 3 ");
  print_list(queue->head);

  printf("Dequeue %i ", dequeue());
  print_list(queue->head);

  enqueue(4);
  printf("Enqueue 4 ");
  print_list(queue->head);

  printf("Dequeue %i ", dequeue());
  print_list(queue->head);

  printf("Dequeue %i ", dequeue());
  print_list(queue->head);
}
