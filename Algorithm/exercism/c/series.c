#include <stdlib.h>
#include <string.h>

#define MAX_SERIES_LENGTH 5
#define MAX_SERIES_RESULTS 8
#define MAX_INPUT_TEXT_LENGTH 8

typedef struct slices
{
  unsigned int substring_count;
  char **substring;
} slices_t;

slices_t slices(char *input_text, unsigned int substring_length);

slices_t slices(char *input_text, unsigned int substring_length)
{
  int num_sub_strings = 0;

  if (substring_length >= 1 && substring_length <= strlen(input_text))
  {
    num_sub_strings = strlen(input_text) - substring_length + 1;
  }

  char **substrings = calloc(num_sub_strings, sizeof(char *));

  for (int i = 0; i < num_sub_strings; i++)
  {
    substrings[i] = calloc(substring_length + 1, sizeof(char));
    strncpy(substrings[i], input_text + i, substring_length);
  }

  return (slices_t){num_sub_strings, substrings};
}
