#include <stdlib.h>
#include <string.h>

char *reverse(const char *value);

char *reverse(const char *value)
{
  int length = strlen(value);
  char *rev_str = calloc(length + 1, sizeof(char));

  for (int i = 0; i < length; i++)
  {
    rev_str[i] = value[length - i - 1];
  }

  rev_str[length] = '\0';
  return rev_str;
}