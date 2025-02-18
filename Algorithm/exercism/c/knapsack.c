#include <stdlib.h>
#include <stddef.h>

typedef struct
{
  size_t weight;
  size_t value;
} item_t;

size_t maximum_value(size_t maximum_weight, const item_t *items, size_t item_count);

#define max(a, b) (a > b ? a : b)

size_t maximum_value(size_t maximum_weight, const item_t *items, size_t item_count)
{
  size_t *max_stack = calloc(maximum_weight + 1, sizeof(size_t));

  for (int i = item_count; i > 0; i--, items++)
  {
    for (size_t j = maximum_weight; j >= items->weight; j--)
    {
      max_stack[j] = max(max_stack[j], max_stack[j - items->weight] + items->value);
    }
  }

  return max_stack[maximum_weight];
}
