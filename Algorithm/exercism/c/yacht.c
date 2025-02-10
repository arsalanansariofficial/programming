#define DIES 5
#define FACES 6

typedef enum
{
  ONES,
  TWOS,
  THREES,
  FOURS,
  FIVES,
  SIXES,
  FULL_HOUSE,
  FOUR_OF_A_KIND,
  LITTLE_STRAIGHT,
  BIG_STRAIGHT,
  CHOICE,
  YACHT
} category_t;

typedef struct
{
  int faces[DIES];
} dice_t;

int get_index_from_face_count(int face_count[], int count);
int score(dice_t dice, category_t category);

int get_index_from_face_count(int face_count[], int count)
{
  for (int i = 0; i < FACES; i++)
  {
    if (face_count[i] >= count)
    {
      return i;
    }
  }

  return -1;
}

int score(dice_t dice, category_t category)
{
  int sum_of_faces = 0, face_count[FACES] = {0};

  for (int i = 0; i < DIES; i++)
  {
    sum_of_faces += dice.faces[i];
    face_count[dice.faces[i] - 1]++;
  }

  if (category == CHOICE)
  {
    return sum_of_faces;
  }

  if (category == BIG_STRAIGHT)
  {
    return sum_of_faces == 20 ? 30 : 0;
  }

  if (category == LITTLE_STRAIGHT)
  {
    return sum_of_faces == 15 ? 30 : 0;
  }

  if (category == YACHT)
  {
    if (get_index_from_face_count(face_count, 5) == -1)
    {
      return 0;
    }

    return 50;
  }

  if (category == FOUR_OF_A_KIND)
  {
    int index = get_index_from_face_count(face_count, 4);

    if (index == -1)
    {
      return 0;
    }

    return (index + 1) * 4;
  }

  if (category == FULL_HOUSE)
  {
    int full_house_count = 0;

    for (int i = 0; i < FACES; i++)
    {
      if (face_count[i] == 2 || face_count[i] == 3)
      {
        full_house_count += face_count[i];
      }
    }

    if (full_house_count == 5)
    {
      return sum_of_faces;
    }

    return 0;
  }

  return (category + 1) * face_count[category];
}
