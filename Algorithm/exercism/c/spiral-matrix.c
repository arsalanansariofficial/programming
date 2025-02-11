#include <stdlib.h>

typedef struct
{
  int size;
  int **matrix;
} spiral_matrix_t;

spiral_matrix_t *spiral_matrix_create(int size);
void spiral_matrix_destroy(spiral_matrix_t *spiral);

void spiral_matrix_destroy(spiral_matrix_t *spiral)
{
  for (int i = 0; i < spiral->size; i++)
  {
    free(spiral->matrix[i]);
  }

  free(spiral->matrix);
  free(spiral);
}

spiral_matrix_t *spiral_matrix_create(int size)
{
  spiral_matrix_t *spiral = calloc(1, sizeof(spiral_matrix_t));

  if (size < 1)
  {
    return spiral;
  }

  spiral->size = size;
  spiral->matrix = calloc(size, sizeof(int *));

  for (int i = 0; i < size; i++)
  {
    spiral->matrix[i] = calloc(size, sizeof(int));
  }

  int top = 0;
  int left = -1;
  int right = size - 1;
  int bottom = size - 1;

  for (int n = 1; n <= size * size;)
  {
    for (int x = ++left; x <= right; x++)
    {
      spiral->matrix[top][x] = n++;
    }

    for (int y = ++top; y <= bottom; y++)
    {
      spiral->matrix[y][right] = n++;
    }

    for (int x = --right; x >= left; x--)
    {
      spiral->matrix[bottom][x] = n++;
    }

    for (int y = --bottom; y >= top; y--)
    {
      spiral->matrix[y][left] = n++;
    }
  }

  return spiral;
}