#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool answer(const char *question, int *result);

bool answer(const char *question, int *result)
{
  int number = 0, count = 0;

  if (!sscanf(question, "What is %d %n", result, &count))
  {
    return false;
  }

  while (*(question + count + 1))
  {
    question += count;

    if (sscanf(question, " plus %d %n", &number, &count))
    {
      *result += number;
    }
    else if (sscanf(question, " minus %d %n", &number, &count))
    {
      *result -= number;
    }
    else if (sscanf(question, " divided by %d %n", &number, &count))
    {
      *result /= number;
    }
    else if (sscanf(question, " multiplied by %d %n", &number, &count))
    {
      *result *= number;
    }
    else
    {
      return false;
    }
  }

  return true;
}