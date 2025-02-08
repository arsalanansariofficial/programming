#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

#define MAX_PROTEINS 10

typedef enum
{
  Methionine,
  Phenylalanine,
  Leucine,
  Serine,
  Tyrosine,
  Cysteine,
  Tryptophan,
  Stop
} protein_t;

typedef struct
{
  bool valid;
  size_t count;
  protein_t proteins[MAX_PROTEINS];
} proteins_t;

protein_t get_protien_from_rna(char codon[]);
proteins_t proteins(const char *const rna);

protein_t get_protien_from_rna(char codon[])
{
  if (!strcmp(codon, "AUG"))
  {
    return Methionine;
  }

  if (!strcmp(codon, "UUU") || !strcmp(codon, "UUC"))
  {
    return Phenylalanine;
  }

  if (!strcmp(codon, "UUA") || !strcmp(codon, "UUG"))
  {
    return Leucine;
  }

  if (!strcmp(codon, "UCU") || !strcmp(codon, "UCC") || !strcmp(codon, "UCA") || !strcmp(codon, "UCG"))
  {
    return Serine;
  }

  if (!strcmp(codon, "UAU") || !strcmp(codon, "UAC"))
  {
    return Tyrosine;
  }

  if (!strcmp(codon, "UGU") || !strcmp(codon, "UGC"))
  {
    return Cysteine;
  }

  if (!strcmp(codon, "UGG"))
  {
    return Tryptophan;
  }

  if (!strcmp(codon, "UAA") || !strcmp(codon, "UAG") || !strcmp(codon, "UGA"))
  {
    return Stop;
  }

  return -1;
}

proteins_t proteins(const char *const rna)
{
  proteins_t result = {true, 0, {0}};

  for (int i = 0, p = 0; rna[i]; i += 3, p++)
  {
    char codon[4] = {0};
    strncpy(codon, rna + i, 3);
    int protein_type = get_protien_from_rna(codon);

    if (protein_type == -1)
    {
      result.valid = false;
      return result;
    }

    if (protein_type == Stop)
    {
      return result;
    }

    result.count++;
    result.proteins[p] = protein_type;
  }

  return result;
}