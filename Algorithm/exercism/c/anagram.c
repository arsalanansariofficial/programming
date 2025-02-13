#include <stdio.h>
#include <stddef.h>

#define MAX_STR_LEN 20

enum anagram_status
{
  UNCHECKED = -1,
  NOT_ANAGRAM,
  IS_ANAGRAM
};

struct candidate
{
  enum anagram_status is_anagram;
  const char *word;
};

struct candidates
{
  struct candidate *candidate;
  size_t count;
};

void find_anagrams(const char *subject, struct candidates *candidates);

void find_anagrams(const char *subject, struct candidates *candidates)
{
  size_t i = 0;

outer_loop:
  while (i < candidates->count)
  {
    int is_equal = 1, mask[26] = {0};
    const char *tmp = subject, *word = candidates->candidate[i].word;

    while (*tmp && *word)
    {
      mask[(*tmp | 32) - 'a'] += 1;
      mask[(*word | 32) - 'a'] -= 1;

      if ((*tmp | 32) != (*word | 32))
      {
        is_equal = 0;
      }

      tmp++;
      word++;
    }

    for (int j = 0; j < 26; j++)
    {
      if (mask[j])
      {
        candidates->candidate[i].is_anagram = NOT_ANAGRAM;
        i++;
        goto outer_loop;
      }
    }

    candidates->candidate[i].is_anagram = is_equal ? NOT_ANAGRAM : *tmp == *word;
    i++;
  }
}
