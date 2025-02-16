#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 20
#define MAX_WORD_LENGTH 50

typedef struct word_count_word
{
  char text[MAX_WORD_LENGTH + 1];
  int count;
} word_count_word_t;

int compare_words(const void *a, const void *b);
int count_words(const char *sentence, word_count_word_t *words);

int compare_words(const void *a, const void *b)
{
  return strcmp(((word_count_word_t *)a)->text, ((word_count_word_t *)b)->text);
}

int count_words(const char *sentence, word_count_word_t *words)
{
  int i = 0, index = 0;

  while (sentence[i])
  {
    if (isalnum(sentence[i]))
    {
      int j = 0, is_unique = 1;

      while (isalnum(sentence[i]) || (sentence[i] == '\'' && isalpha(sentence[i + 1])))
      {
        words[index].text[j++] = tolower(sentence[i++]);
      }

      words[index].text[j] = 0;

      for (int k = 0; k < index; k++)
      {
        if (!strcmp(words[k].text, words[index].text))
        {
          is_unique = 0;
          words[k].count++;
        }
      }

      if (is_unique)
      {
        words[index++].count++;
        continue;
      }

      memset(words[index].text, 0, MAX_WORD_LENGTH + 1);
      continue;
    }

    i++;
  }

  qsort(words, index, sizeof(word_count_word_t), compare_words);
  return index;
}
