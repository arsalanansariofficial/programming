#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void free_annotation(char **annotation);
char **annotate(const char **minefield, const size_t rows);

void free_annotation(char **annotation)
{
  free(annotation[0]);
  free(annotation);
}

char **annotate(const char **minefield, const size_t rows)
{
  if (!rows)
  {
    return NULL;
  }

  int i = rows, j = 0, length = strlen(minefield[0]);
  char **result = calloc(rows, sizeof(char *)), *row = calloc(rows, length + 1);

  while (i--)
  {
    result[i] = memcpy(row + i * (length + 1), minefield[i], length + 1);
  }

  for (i = rows - 1; i >= 0; i--)
  {
    for (j = 0; j < length; j++)
    {
      if (minefield[i][j] != '*')
      {
        continue;
      }

      for (int x = i ? -1 : 0; x < 2 && i + x < (int)rows; x++)
      {
        for (int y = j ? -1 : 0; y < 2 && j + y < length; y++)
        {
          if (result[i + x][j + y] == '*')
          {
            continue;
          }

          result[i + x][j + y] = result[i + x][j + y] == ' ' ? '1' : result[i + x][j + y] + 1;
        }
      }
    }
  }

  return result;
}