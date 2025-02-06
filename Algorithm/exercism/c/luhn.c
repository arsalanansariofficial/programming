#include <stdbool.h>

bool luhn(const char *num);

bool luhn(const char *num)
{
  if (!num[0] || num[0] == ' ' || !(num[1]))
  {
    return false;
  }

  int sum = 0;
  int is_alt = 0;
  int length = 0;

  while (num[length])
  {
    length++;
  }

  for (int i = length - 1; i >= 0; i--)
  {
    if (num[i] == ' ')
    {
      continue;
    }

    if (num[i] >= '0' && num[i] <= '9')
    {
      if (!is_alt)
      {
        is_alt = 1;
        sum += num[i] - '0';
        continue;
      }

      is_alt = 0;
      int double_digit = (num[i] - '0') * 2;
      sum += double_digit > 9 ? double_digit - 9 : double_digit;
      continue;
    }

    return false;
  }

  if (sum % 10 == 0)
  {
    return true;
  }

  return false;
}