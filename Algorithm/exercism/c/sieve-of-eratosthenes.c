#include <stdint.h>
#include <stddef.h>

void init_array(uint32_t array[], size_t length);
uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes);

void init_array(uint32_t array[], size_t length)
{
  for (size_t i = 0; i < length; i++)
  {
    array[i] = 0;
  }
}

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
  uint32_t num_of_primes = 0;
  uint32_t non_primes[limit + 1];

  init_array(primes, max_primes);
  init_array(non_primes, limit + 1);

  for (size_t i = 2, p = 0; i <= limit; i++)
  {
    if (p >= max_primes)
    {
      break;
    }

    if (!non_primes[i])
    {
      primes[p++] = i;
    }

    for (size_t j = 2; j * i <= limit; j++)
    {
      uint32_t multiple = j * i;
      non_primes[multiple] = 1;
    }
  }

  for (size_t i = 0; i < max_primes; i++)
  {
    if (primes[i])
    {
      num_of_primes++;
    }
  }

  return num_of_primes;
}