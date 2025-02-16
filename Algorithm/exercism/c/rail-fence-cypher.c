#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef enum
{
  ENCODE,
  DECODE
} CYPHER;

char *encode(char *text, size_t rails);
char *decode(char *ciphertext, size_t rails);
char *cipher(char *input, size_t rails, CYPHER action);

#define NEXT_STEP(current, max_step) current == max_step ? max_step : max_step - current

char *encode(char *input, size_t rails)
{
  return cipher(input, rails, ENCODE);
}

char *decode(char *input, size_t rails)
{
  return cipher(input, rails, DECODE);
}

char *cipher(char *input, size_t rails, CYPHER action)
{
  const size_t len = strlen(input);
  const size_t max_step = 2 * (rails - 1);
  char *result = calloc(len + 1, sizeof(char));

  for (size_t rail = 0, dest = 0; rail < rails; rail++)
  {
    size_t origin = rail;
    size_t step = NEXT_STEP((max_step - 2 * rail), max_step);

    while (origin < len)
    {
      if (action == ENCODE)
      {
        result[dest] = input[origin];
      }
      else
      {
        result[origin] = input[dest];
      }

      step = NEXT_STEP(step, max_step);
      dest++, origin += step;
    }
  }

  return result;
}