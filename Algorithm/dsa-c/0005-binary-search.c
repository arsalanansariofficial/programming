#include <math.h>
#include <stdio.h>

int binary_search(int array[], int key, int start, int end)
{
  while (start <= end)
  {
    int mid = floor((start + end) / 2);

    if (array[mid] == key)
    {
      return mid;
    }

    if (array[mid] < key)
    {
      start = mid + 1;
      continue;
    }

    end = mid - 1;
  }

  return -1;
}

int binary_search_rec(int array[], int key, int start, int end)
{
  if (start > end)
  {
    return -1;
  }

  int mid = start + (end - start) / 2;

  if (array[mid] == key)
    return mid;

  if (array[mid] < key)
  {
    return binary_search_rec(array, key, mid + 1, end);
  }

  return binary_search_rec(array, key, start, mid - 1);
}

int main()
{
  int array[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

  printf("Element found at index %i\n", binary_search(array, 73, 0, 24));
  printf("Element found at index %i\n", binary_search_rec(array, 97, 0, 24));
}