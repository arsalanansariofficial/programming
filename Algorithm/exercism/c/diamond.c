#include <string.h>
#include <stdlib.h>

void free_diamond(char **diamond);
char **make_diamond(const char letter);

void free_diamond(char **diamond)
{
  for (size_t i = 0, j = strlen(diamond[0]) / 2; i <= j; i++)
  {
    free(diamond[i]);
  }

  free(diamond);
}

char **make_diamond(const char letter)
{
  const size_t length = (2 * (1 + (letter - 'A'))) - 1;
  const size_t mid = length / 2;

  char **diamond_array = calloc(length, sizeof(char *));

  for (char ch = 'A', i = length - 1; ch <= letter; i--, ch++)
  {
    char *line = calloc(length + 1, sizeof(char));
    memset(line, ' ', length);

    line[mid - (ch - 'A')] = line[mid + (ch - 'A')] = ch;
    diamond_array[ch - 'A'] = diamond_array[i - 0] = line;
  }

  return diamond_array;
}
