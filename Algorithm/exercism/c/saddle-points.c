#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#define MAX_SADDLE_POINTS 100

typedef struct
{
  uint8_t row;
  uint8_t column;
} saddle_point_t;

typedef struct
{
  size_t count;
  saddle_point_t points[MAX_SADDLE_POINTS];
} saddle_points_t;

void free_saddle_points(saddle_points_t *tmp);
saddle_points_t *saddle_points(size_t rows, size_t cols, uint8_t matrix[rows][cols]);

void free_saddle_points(saddle_points_t *saddle_points)
{
  free(saddle_points);
}

saddle_points_t *saddle_points(size_t rows, size_t cols, uint8_t matrix[rows][cols])
{
  saddle_points_t *saddle_points = calloc(1, sizeof(saddle_points_t));

  for (size_t i = 0; i < rows; i++)
  {
    uint8_t row_max = matrix[i][0];

    for (size_t j = 1; j < cols; j++)
    {
      if (matrix[i][j] > row_max)
      {
        row_max = matrix[i][j];
      }
    }

    for (size_t j = 0; j < cols; j++)
      if (matrix[i][j] == row_max)
      {
        size_t r = i;

        for (size_t k = 0; k < rows; k++)
        {
          if (matrix[k][j] < matrix[r][j])
          {
            r = k;
          }
        }

        if (r == i)
        {
          saddle_points->points[saddle_points->count++] = (saddle_point_t){r + 1, j + 1};
        }
      }
  }

  return realloc(saddle_points, sizeof(size_t) + saddle_points->count * sizeof(saddle_point_t));
}
