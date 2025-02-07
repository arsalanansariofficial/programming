#include <stddef.h>

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit);

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit)
{
  size_t sum = 0;
  size_t multiples[limit];

  for (size_t i = 0; i < limit; i++)
  {
    multiples[i] = 0;
  }

  for (size_t i = 0; i < number_of_factors; i++)
  {
    size_t j = 1, factor, multiple;
    multiple = factor = factors[i];

    while (multiple < limit && multiple > 0)
    {
      if (!multiples[multiple])
      {
        multiples[multiple] = 1;
      }

      j++;
      multiple = factor * j;
    }
  }

  for (size_t i = 0; i < limit; i++)
  {
    if (multiples[i])
    {
      sum += i;
    }
  }

  return sum;
}
