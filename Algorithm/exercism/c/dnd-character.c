#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int strength;
  int dexterity;
  int constitution;
  int intelligence;
  int wisdom;
  int charisma;
  int hitpoints;
} dnd_character_t;

int compare(const void *a, const void *b);
int modifier(int score);

int ability(void);
dnd_character_t make_dnd_character(void);

int compare(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

int modifier(int score)
{
  return floor((score - 10) / 2.0);
}

int ability()
{
  int sum = 0;
  int length = 4;
  int min = 1, max = 6;

  srand(time(0));
  int rolls[length];

  for (int i = 0; i < length; i++)
  {
    rolls[i] = (rand() % max) + min;
  }

  qsort(rolls, 4, sizeof(int), compare);

  for (int i = 1; i < length; i++)
  {
    sum += rolls[i];
  }

  return sum;
}

dnd_character_t make_dnd_character()
{
  dnd_character_t character = {ability(), ability(), ability(), ability(), ability(), ability(), 10 + modifier(character.constitution)};
  return character;
}
