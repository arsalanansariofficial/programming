#include <ctype.h>
#include <string.h>
#include <stdbool.h>

char const *hey_bob(char const *greeting);

static char const *const answers[] = {"Whatever.", "Sure.", "Whoa, chill out!", "Calm down, I know what I'm doing!"};

char const *hey_bob(char const *greeting)
{
  if (!greeting || !*greeting)
  {
    return "Fine. Be that way!";
  }

  char const *end_pos = greeting + strlen(greeting) - 1;

  while (end_pos > greeting && isspace(*end_pos))
  {
    end_pos--;
  }

  if (isspace(*end_pos))
  {
    return "Fine. Be that way!";
  }

  char const *message = greeting;
  bool shout = true, has_letter = false;

  while (message <= end_pos)
  {
    if (isalpha(*message))
    {
      has_letter = true;

      if (!isupper(*message))
      {
        shout = false;
        break;
      }
    }

    message++;
  }

  int is_question = *end_pos == '?' ? 1 : 0;
  int is_shout = shout && has_letter ? 2 : 0;

  return answers[is_shout + is_question];
}