#include "math.h"
#include <stdint.h>

uint64_t square(uint8_t index);
uint64_t total(void);

uint64_t square(uint8_t index)
{
  if (index < 1 || index > 64)
  {
    return 0;
  }

  // 5 binary 0101
  // 10 binary 1010 (After shifting left one time)
  // number << index (index will be the number of times bits to be shifted)
  return (uint64_t)1 << (index - 1);
}

uint64_t total(void)
{
  uint64_t sum = 0;

  for (uint8_t i = 0; i < 64; i++)
  {
    sum += (uint64_t)1 << i;
  }

  return sum;
}