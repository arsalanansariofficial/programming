#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define MAXFACTORS 10

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]);

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
  uint64_t i = 0;
  uint64_t factor = 2;

  while (n > 1)
  {
    if (n % factor == 0)
    {
      factors[i++] = factor;
      n /= factor;
      continue;
    }

    factor++;
  }

  return i;
}