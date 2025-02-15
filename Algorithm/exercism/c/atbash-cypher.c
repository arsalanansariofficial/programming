#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *atbash_encode(const char *input);
char *atbash_decode(const char *input);

#define CHAR_SET 5

char *atbash_encode(const char *input)
{
  int i = 0, length = strlen(input);
  char *tmp = calloc(length + (length / CHAR_SET) + 1, sizeof(char));

  while (*input)
  {
    if (!isalnum(*input))
    {
      input++;
      continue;
    }

    if ((i + 1) % 6 == 0)
    {
      tmp[i++] = ' ';
    }

    tmp[i++] = isdigit(*input) ? *input++ : 'z' - (tolower(*input++) - 'a');
  }

  tmp = realloc(tmp, (i + 1) * sizeof(char));
  return tmp;
}

char *atbash_decode(const char *input)
{
  int i = 0;
  char *tmp = calloc(strlen(input) + 1, sizeof(char));

  while (*input)
  {
    if (!isalnum(*input))
    {
      input++;
      continue;
    }

    tmp[i++] = isdigit(*input) ? *input++ : 'z' - (tolower(*input++) - 'a');
  }

  return tmp;
}