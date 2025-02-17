#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

int64_t largest_series_product(char *digits, size_t span);

int64_t largest_series_product(char *digits, size_t span)
{
  int64_t largest_product = 0;
  size_t digit_len = strlen(digits);

  if (span > digit_len)
  {
    return -1;
  }

  for (size_t i = 0; i < digit_len - span + 1; i++)
  {
    int64_t product = 1;

    for (size_t j = 0; j < span; j++)
    {
      if (!isdigit(digits[i + j]))
      {
        return -1;
      }

      product *= digits[i + j] - '0';
    }

    if (product > largest_product)
    {
      largest_product = product;
    }
  }

  return largest_product;
}