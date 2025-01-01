#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 3

int dequeue();
bool is_full();
bool is_empty();
void print_queue();
void enqueue(int value);

typedef struct Queue
{
  int size;
  int read_index;
  int write_index;
  int array[LENGTH];
} Queue;

Queue queue = {0, 0, 0};

bool is_empty()
{
  return queue.size == 0;
}

bool is_full()
{
  return queue.size == LENGTH;
}

void enqueue(int value)
{
  if (is_full())
  {
    return;
  }

  queue.size++;
  queue.array[queue.write_index] = value;
  queue.write_index = (queue.write_index + 1) % LENGTH;
}

int dequeue()
{
  if (is_empty())
  {
    return -1;
  }

  int value = queue.array[queue.read_index];

  queue.size--;
  queue.read_index = (queue.read_index + 1) % LENGTH;
  return value;
}

void print_queue()
{
  if (is_empty(queue))
  {
    printf("Queue is empty\n");
    return;
  }

  for (int i = 0; i < queue.size; i++)
  {
    int element = queue.array[(queue.read_index + i) % LENGTH];

    if (i + 1 < queue.size)
    {
      printf("%i --> ", element);
    }
    else
    {
      printf("%i\n", element);
    }
  }
}

int main()
{
  enqueue(1);
  printf("Enqueue 1 ");
  print_queue();

  enqueue(2);
  printf("Enqueue 2 ");
  print_queue();

  enqueue(3);
  printf("Enqueue 3 ");
  print_queue();

  printf("Dequeue %i ", dequeue());
  print_queue();

  enqueue(4);
  printf("Enqueue 4 ");
  print_queue();

  printf("Dequeue %i ", dequeue());
  print_queue();

  printf("Dequeue %i ", dequeue());
  print_queue();
}
