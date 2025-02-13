#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *abbreviate(const char *phrase);

char *abbreviate(const char *phrase)
{
  if (!phrase || !(*phrase))
  {
    return NULL;
  }

  char *acronyms = calloc(strlen(phrase) + 1, sizeof(char));

  if (!acronyms)
  {
    return NULL;
  }

  char *acronyms_start = acronyms;
  const char start_trigger[] = " -";

  for (int start = 1; *phrase; phrase++)
  {
    if (start && isalpha(*phrase))
    {
      start = 0;
      *acronyms++ = toupper(*phrase);
      continue;
    }

    if (strchr(start_trigger, *phrase))
    {
      start = 1;
    }
  }

  return acronyms_start;
}