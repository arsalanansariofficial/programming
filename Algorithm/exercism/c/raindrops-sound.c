#include <stdio.h>
#include <string.h>

void convert(char result[], int drops);

typedef struct Sound
{
  int divisor;
  char *sound;
} Sound;

void convert(char result[], int drops)
{
  Sound sounds[] = {{3, "Pling"}, {5, "Plang"}, {7, "Plong"}};
  int sounds_len = sizeof(sounds) / sizeof(sounds[0]);

  for (int i = 0; i < sounds_len; i++)
  {
    if (drops % sounds[i].divisor == 0)
    {
      strcat(result, sounds[i].sound);
    }
  }

  if (!*result)
  {
    sprintf(result, "%i", drops);
  }
}
