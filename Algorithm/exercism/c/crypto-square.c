#include <math.h>
#include <stdlib.h>
#include <string.h>

char *ciphertext(const char *input);

char *ciphertext(const char *input)
{
  size_t a = 0, m, n, o;
  char *l, *k = (char *)input, *j = malloc(strlen(input) + 1);

  while (*k)
  {
    if (*k >= 'a' && *k <= 'z')
    {
      j[a++] = *k;
    }

    if (*k >= 'A' && *k <= 'Z')
    {
      j[a++] = *k + 'a' - 'A';
    }

    if (*k >= '0' && *k <= '9')
    {
      j[a++] = *k;
    }

    k++;
  }

  if (!a)
  {
    free(j);
    return calloc(1, 1);
  }

  size_t x = ceil(sqrt(a)), y = ceil((double)a / x), b = x * y + x - 1;

  for (l = k = malloc(b + 1), m = n = 0; m < x; m++, *k++ = ' ')
  {
    for (n = m, o = 0; o < y; o++, n += x)
    {
      *k++ = n < a ? j[n] : ' ';
    }
  }

  free(j);
  l[b] = 0;
  return l;
}