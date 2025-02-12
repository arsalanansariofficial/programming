#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int list_element_t;

typedef struct
{
  size_t length;
  list_element_t elements[];
} list_t;

void delete_list(list_t *list);
list_t *new_list(size_t length, list_element_t elements[]);

size_t length_list(list_t *list);
list_t *reverse_list(list_t *list);
list_t *append_list(list_t *list1, list_t *list2);
list_t *filter_list(list_t *list, bool (*filter)(list_element_t));
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t));

list_element_t foldl_list(list_t *list, list_element_t initial, list_element_t (*foldl)(list_element_t, list_element_t));
list_element_t foldr_list(list_t *list, list_element_t initial, list_element_t (*foldr)(list_element_t, list_element_t));

void delete_list(list_t *list)
{
  free(list);
}

list_t *new_list(size_t length, list_element_t elements[])
{
  list_t *list = malloc(sizeof(list_t) + sizeof(list_element_t) * length);

  list->length = length;
  memcpy(list->elements, elements, length * sizeof(list_element_t));

  return list;
}

size_t length_list(list_t *list)
{
  return list->length;
}

list_t *reverse_list(list_t *list)
{
  list_t *rvs = malloc(sizeof(list_t) + sizeof(list_element_t) * list->length);

  rvs->length = list->length;

  for (size_t i = 0; i < list->length; i++)
  {
    rvs->elements[list->length - i - 1] = list->elements[i];
  }

  return rvs;
}

list_t *append_list(list_t *list1, list_t *list2)
{
  size_t length = list1->length + list2->length;
  list_t *list = malloc(sizeof(list_t) + sizeof(list_element_t) * length);
  list->length = length;

  memcpy(list->elements, list1->elements, sizeof(list_element_t) * list1->length);
  memcpy(list->elements + list1->length, list2->elements, sizeof(list_element_t) * list2->length);

  return list;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t))
{
  int length = 0;
  list_element_t *filtered_List = malloc(sizeof(list_t) + sizeof(list_element_t) * list->length);

  for (size_t i = 0; i < list->length; i++)
  {
    if (filter(list->elements[i]))
    {
      filtered_List[length++] = list->elements[i];
    }
  }

  return new_list(length, filtered_List);
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t))
{
  int length = 0;
  list_element_t *mapped_List = malloc(sizeof(list_t) + sizeof(list_element_t) * list->length);

  for (size_t i = 0; i < list->length; ++i)
  {
    mapped_List[length++] = map(list->elements[i]);
  }

  return new_list(length, mapped_List);
}

list_element_t foldl_list(list_t *list, list_element_t initial, list_element_t (*foldl)(list_element_t, list_element_t))
{
  list_element_t accumulator = initial;

  for (size_t i = 0; i < list->length; i++)
  {
    accumulator = foldl(list->elements[i], accumulator);
  }

  return accumulator;
}

list_element_t foldr_list(list_t *list, list_element_t initial, list_element_t (*foldr)(list_element_t, list_element_t))
{
  list_element_t accumulator = initial;

  for (size_t i = 0; i < list->length; i++)
  {
    accumulator = foldr(list->elements[list->length - i - 1], accumulator);
  }

  return accumulator;
}
