#include <stddef.h>

int binary_search_util(int array[], int left, int mid, int right);
const int *binary_search(int value, const int *arr, size_t length);

int binary_search_util(int array[], int value, int left, int right)
{
  if (right < left)
  {
    return -1;
  }

  int mid = left + (right - left) / 2;

  if (array[mid] == value)
  {
    return mid;
  }

  if (array[mid] < value)
  {
    return binary_search_util(array, value, mid + 1, right);
  }

  return binary_search_util(array, value, left, mid - 1);
}

const int *binary_search(int value, const int *arr, size_t length)
{
  int index = binary_search_util((int *)arr, value, 0, length - 1);

  if (index == -1)
  {
    return NULL;
  }

  return arr + index;
}
