#include <string.h>

typedef enum
{
  GRASS = 'G',
  CLOVER = 'C',
  VIOLETS = 'V',
  RADISHES = 'R'
} plant_t;

typedef struct
{
  plant_t plants[4];
} plants_t;

plants_t plants(const char *row_1, const char *student);

plants_t plants(const char *row_1, const char *student)
{
  size_t i = (student[0] - 'A') * 2;
  const char *row_2 = strchr(row_1, '\n') + 1;
  return (plants_t){{row_1[i], row_1[i + 1], row_2[i], row_2[i + 1]}};
}