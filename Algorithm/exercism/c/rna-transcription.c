#include <string.h>
#include <stdlib.h>

char *to_rna(const char *dna);

char *to_rna(const char *dna)
{
  if (!dna)
  {
    return NULL;
  }

  int dna_len = (int)strlen(dna);
  char *rna = calloc(dna_len + 1, sizeof(char));

  if (!rna)
  {
    return NULL;
  }

  for (int i = 0; i < dna_len; i++)
  {
    switch (dna[i])
    {
    case 'G':
      rna[i] = 'C';
      break;

    case 'C':
      rna[i] = 'G';
      break;

    case 'T':
      rna[i] = 'A';
      break;

    default:
      rna[i] = 'U';
    }
  }

  return rna;
}
