#include <stdlib.h>
#include <stddef.h>

typedef struct
{
  int value;
  const char *keys;
} legacy_map;

typedef struct
{
  char key;
  int value;
} new_map;

int compare(const void *lhs, const void *rhs);
int convert(const legacy_map *input, const size_t input_len, new_map **output);

int compare(const void *lhs, const void *rhs)
{
  return ((const new_map *)lhs)->key - ((const new_map *)rhs)->key;
}

int convert(const legacy_map *input, const size_t input_len, new_map **output)
{
  int len = 0;
  *output = calloc(26, sizeof(new_map));

  for (size_t i = 0; i < input_len; i++)
  {
    for (size_t j = 0; input[i].keys[j]; j++, len++)
    {
      (*output)[len].value = input[i].value;
      (*output)[len].key = input[i].keys[j] + ('a' - 'A');
    }
  }

  qsort(*output, len, sizeof(new_map), compare);
  *output = realloc(*output, len * sizeof(new_map));

  return len;
}
