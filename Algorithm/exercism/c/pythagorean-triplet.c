#include <stdlib.h>
#include <stdint.h>

typedef struct
{
  uint16_t a;
  uint16_t b;
  uint16_t c;
} triplet_t;

typedef struct
{
  uint16_t count;
  triplet_t triplets[];
} triplets_t;

void free_triplets(triplets_t *t);
triplets_t *triplets_with_sum(uint16_t sum);

void free_triplets(triplets_t *t)
{
  free(t);
}

triplets_t *triplets_with_sum(uint16_t sum)
{
  triplets_t *trips = calloc(sum, sizeof(triplet_t));

  for (uint16_t a = 1; a < sum / 3; a++)
  {
    for (uint16_t b = a + 1; b < sum >> 1; b++)
    {
      uint16_t c = sum - a - b;

      if (a * a + b * b == c * c)
      {
        trips->triplets[trips->count++] = (triplet_t){a, b, c};
      }
    }
  }

  return trips;
}
