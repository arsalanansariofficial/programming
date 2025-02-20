#include <stdbool.h>

typedef enum
{
  BUCKET_ID_1,
  BUCKET_ID_2
} bucket_id_t;

typedef unsigned int liters_t;

typedef struct
{
  bool possible;
  int move_count;
  bucket_id_t goal_bucket;
  liters_t other_bucket_liters;
} bucket_result_t;

bucket_result_t measure(liters_t b_1_size, liters_t b_2_size, liters_t goal, bucket_id_t start);

bucket_result_t measure(liters_t b_1_size, liters_t b_2_size, liters_t goal, bucket_id_t start)
{
  if (start)
  {
    bucket_result_t tmp = measure(b_2_size, b_1_size, goal, !start);
    tmp.goal_bucket = !tmp.goal_bucket;
    return tmp;
  }

  liters_t x = 0, y = 0;

  for (unsigned int i = 1; i < 255; i++)
  {
    if (x == 0)
    {
      x = b_1_size;
    }
    else if (b_2_size == goal)
    {
      y = b_2_size;
    }
    else if (y == b_2_size)
    {
      y = 0;
    }
    else
    {
      liters_t tmp = y;
      y = (b_2_size <= x + y) ? b_2_size : x + y;
      x -= y - tmp;
    }

    if (x == goal)
    {
      return (bucket_result_t){true, i, BUCKET_ID_1, y};
    }
    if (y == goal)
    {
      return (bucket_result_t){true, i, BUCKET_ID_2, x};
    }
  }

  return (bucket_result_t){false, 0, 0, 0};
}