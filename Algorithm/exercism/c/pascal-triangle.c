#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

void free_triangle(uint8_t **triangle, size_t rows);
uint8_t **create_triangle(size_t rows);

#define MIN_ROWS(rows) (rows > 0 ? rows : 1)

void free_triangle(uint8_t **triangle, size_t rows)
{
  for (size_t i = 0; i < MIN_ROWS(rows); i++)
    free(triangle[i]);

  free(triangle);
}

uint8_t **create_triangle(size_t rows)
{
  uint8_t **triangle = calloc(MIN_ROWS(rows), sizeof(uint8_t *));
  triangle[0] = calloc(MIN_ROWS(rows), sizeof(uint8_t));

  for (size_t i = 0; i < rows; i++)
  {
    triangle[i] = calloc(rows, sizeof(uint8_t));
    triangle[i][0] = 1;

    if (i > 0)
    {
      uint8_t *previous_row = triangle[i - 1];

      for (size_t j = 1; j < rows; j++)
      {
        triangle[i][j] = previous_row[j] + previous_row[j - 1];
      }
    }
  }

  return triangle;
}
