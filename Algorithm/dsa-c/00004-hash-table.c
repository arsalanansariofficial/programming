#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define size 10

int get(int key);
int hash(int key);
bool exists(int key);
int get_index(int key);
void print_hash_table();
void remove_key(int key);
void add(int key, int value);

typedef struct
{
  int key;
  int value;
} Object;

Object *hash_table[size];

int get_index(int key)
{
  int index = hash(key);
  int initial_index = index;

  while (hash_table[index])
  {
    if (hash_table[index]->key == key)
    {
      return index;
    }

    index = hash(index + 1);

    if (index == initial_index)
    {
      break;
    }
  }

  return -1;
}

void print_hash_table()
{
  for (int i = 0; i < size; i++)
  {
    if (hash_table[i])
    {
      printf("%i --> %i\n", hash_table[i]->key, hash_table[i]->value);
    }
  }
}

int hash(int key)
{
  return key % size;
}

void add(int key, int value)
{
  int index = hash(key);

  while (hash_table[index] && hash_table[index]->key != key)
  {
    index = hash(index + 1);
  }

  if (!hash_table[index])
  {
    Object *object = malloc(sizeof(Object));
    object->key = key;
    object->value = value;

    hash_table[index] = object;
  }
}

bool exists(int key)
{
  return get(key) != -1;
}

int get(int key)
{
  int index = get_index(key);
  return index == -1 ? -1 : hash_table[index]->value;
}

void remove_key(int key)
{
  int index = get_index(key);

  if (index == -1)
  {
    return;
  }

  free(hash_table[index]);
  hash_table[index] = NULL;

  int next_index = hash(index + 1);

  while (hash_table[next_index])
  {
    add(hash_table[next_index]->key, hash_table[next_index]->value);
    next_index = hash(next_index + 1);
  }
}

int main()
{
  add(0, 0);
  add(1, 1);
  add(2, 2);

  print_hash_table();

  printf("Has key 0 present %s\n", exists(0) ? "True" : "False");
  printf("Has key 1 present %s\n", exists(1) ? "True" : "False");

  remove_key(0);
  remove_key(2);

  printf("Has key 0 present %s\n", exists(0) ? "True" : "False");
  printf("Has key 2 present %s\n", exists(2) ? "True" : "False");

  print_hash_table();
}
