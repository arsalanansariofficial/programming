#include <ctype.h>
#include <stdbool.h>

bool is_isogram(const char phrase[]);

bool is_isogram(const char phrase[])
{
  if (!phrase)
  {
    return false;
  }

  int letters[26] = {0};

  for (int i = 0; phrase[i]; i++)
  {
    if (isalpha(phrase[i]))
    {
      int index = tolower(phrase[i]) - 'a';

      if (letters[index]++)
      {
        return false;
      }
    }
  }

  return true;
}
