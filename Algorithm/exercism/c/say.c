#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MIN_SAY 0
#define MAX_SAY_LENGTH 200
#define MAX_SAY 999999999999

int say(int64_t input, char **ans);

const char *large[] = {"billion", "million", "thousand"};

const char *small[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

const char *tiny[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

int say(int64_t input, char **ans)
{
  if (input < MIN_SAY || input > MAX_SAY)
  {
    return -1;
  }

  int written = 0;
  int large_index = 0;
  int64_t divisor = 1000000000;
  *ans = calloc(MAX_SAY_LENGTH, sizeof(char));

  while (divisor)
  {
    int group = input / divisor;

    if (group)
    {
      int hundreds = group / 100;

      if (hundreds)
      {
        written += sprintf(*ans + written, "%s hundred ", tiny[hundreds - 1]);
      }

      group -= hundreds * 100;
      int tens = group / 10;

      if (tens == 1)
      {
        written += sprintf(*ans + written, "%s ", tiny[group - 1]);
      }
      else
      {
        if (tens)
        {
          written += sprintf(*ans + written, "%s", small[tens - 2]);
        }

        int ones = group - tens * 10;

        if (ones)
        {
          written += sprintf(*ans + written, "%s%s ", tens > 0 ? "-" : "", tiny[ones - 1]);
        }
      }

      if (large_index < 3)
      {
        written += sprintf(*ans + written, "%s ", large[large_index]);
      }
    }

    input %= divisor, divisor /= 1000, large_index++;
  }

  if (!written)
  {
    written = sprintf(*ans, "zero");
  }

  if ((*ans)[written - 1] == ' ')
  {
    *ans = realloc(*ans, (written) * sizeof(char));
    (*ans)[written - 1] = 0;
    return 0;
  }

  *ans = realloc(*ans, (written + 1) * sizeof(char));
  (*ans)[written] = 0;
  return 0;
}