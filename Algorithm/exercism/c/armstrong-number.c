#include <math.h>
#include <stdio.h>
#include <stdbool.h>

bool is_armstrong_number(int candidate);

bool is_armstrong_number(int candidate)
{
  float number = 0;
  int exponent = 0;

  for (int i = candidate; i; i /= 10)
  {
    exponent++;
  }

  for (int i = candidate; i; i /= 10)
  {
    number += pow(i % 10, exponent);
  }

  if (number == candidate)
  {
    return 1;
  }

  return 0;
}