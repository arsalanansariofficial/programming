#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool is_pangram(const char *sentence);

bool is_pangram(const char *sentence)
{
  if (!sentence || !*sentence)
  {
    return false;
  }

  int alphabet[26] = {0};

  for (int i = 0; sentence[i]; i++)
  {
    if (isalpha(sentence[i]))
    {
      alphabet[tolower(sentence[i]) - 'a'] = 1;
    }
  }

  for (int i = 0; i < 26; i++)
  {
    if (!alphabet[i])
    {
      return false;
    }
  }

  return true;
}