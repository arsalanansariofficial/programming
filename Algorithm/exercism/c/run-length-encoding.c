#include <stdio.h>
#include <stdlib.h>

char *encode(const char *text);
char *decode(const char *data);

char *encode(const char *text)
{
  int i = 0, count = 0, index = 0;
  char *tmp = calloc(1000, sizeof(char));

  while (text[i])
  {
    count = 1;

    while (text[i + count] == text[i])
    {
      count++;
    }

    if (count > 1)
    {
      sprintf(tmp + index, "%d", count);
    }

    while (tmp[index])
    {
      index++;
    }

    tmp[index++] = text[i];
    i += count;
  }

  tmp = realloc(tmp, (index + 1) * sizeof(char));
  tmp[index] = 0;
  return tmp;
}

char *decode(const char *data)
{
  int index = 0;
  char *tmp = calloc(1000, sizeof(char));

  for (int i = 0; data[i]; i++)
  {
    int count = 0;

    while (data[i] >= '0' && data[i] <= '9')
    {
      count = 10 * count + data[i++] - '0';
    }

    count = !count ? 1 : count;

    while (count-- > 0)
    {
      tmp[index++] = data[i];
    }
  }

  tmp = realloc(tmp, (index + 1) * sizeof(char));
  tmp[index] = 0;
  return tmp;
}