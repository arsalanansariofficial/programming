#include <stdio.h>
#include <stdlib.h>

char *count(const char *dna_strand);

char *count(const char *dna_strand)
{
  int A = 0, C = 0, G = 0, T = 0;

  for (int i = 0; dna_strand[i]; i++)
  {
    if (dna_strand[i] == 'A')
    {
      A++;
      continue;
    }

    if (dna_strand[i] == 'C')
    {
      C++;
      continue;
    }

    if (dna_strand[i] == 'G')
    {
      G++;
      continue;
    }

    if (dna_strand[i] == 'T')
    {
      T++;
      continue;
    }

    return calloc(1, sizeof(char));
  }

  int format_len = snprintf(NULL, 0, "A:%i C:%i G:%i T:%i", A, C, G, T) + 1;
  char *result = calloc(format_len, sizeof(char));

  snprintf(result, format_len, "A:%i C:%i G:%i T:%i", A, C, G, T);
  return result;
}