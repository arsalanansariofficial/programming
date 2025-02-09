#include <stdint.h>

uint32_t nth(uint32_t n);

uint32_t nth(uint32_t n)
{
  uint32_t nth_prime = 0;

  for (uint32_t i = 2, p = 0; p < n; i++)
  {
    int is_prime = 1;

    for (uint32_t j = 2; j * j <= i; j++)
    {
      if (i % j == 0)
      {
        is_prime = 0;
        break;
      }
    }

    if (is_prime)
    {
      nth_prime = i;
      p++;
    }
  }

  return nth_prime;
}