#include <stdlib.h>

const char **commands(size_t num);

#define MASK 16
#define SIGNAL_LEN 4

static const char *signals[] = {"wink", "double blink", "close your eyes", "jump"};

const char **commands(size_t num)
{
  const char **output = calloc(SIGNAL_LEN, sizeof(char *));
  int inc = 1, end = SIGNAL_LEN, start = 0, output_index = 0;

  if (num & MASK)
  {
    inc = -1;
    end = -1;
    start = SIGNAL_LEN - 1;
  }

  while (start != end)
  {
    if (num & 1 << start)
    {
      output[output_index++] = signals[start];
    }

    start += inc;
  }

  return output;
}