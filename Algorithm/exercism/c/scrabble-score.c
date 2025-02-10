#include <stdio.h>

unsigned int score(const char *word);

unsigned int score(const char *word)
{
  int score = 0;
  int values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

  for (int i = 0; word[i]; i++)
  {
    char letter = word[i];

    if (letter >= 'A' && letter <= 'Z')
    {
      letter += 32;
    }

    score += values[letter - 'a'];
  }

  return score;
}
