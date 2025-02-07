#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rotate(const char *text, int shift_key);

char *rotate(const char *text, int shift_key)
{
  char *rotated = calloc(strlen(text) + 1, sizeof(char));

  for (int i = 0; text[i]; i++)
  {
    if (text[i] >= 'A' && text[i] <= 'Z')
    {
      rotated[i] = 'A' + (text[i] - 'A' + shift_key) % 26;
      continue;
    }

    if (text[i] >= 'a' && text[i] <= 'z')
    {
      rotated[i] = 'a' + (text[i] - 'a' + shift_key) % 26;
      continue;
    }

    rotated[i] = text[i];
  }

  rotated[strlen(text)] = '\0';
  return rotated;
}