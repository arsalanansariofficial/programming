#define ERROR_VALUE -1

int steps(int start);

int steps(int start)
{
  if (start < 1)
  {
    return ERROR_VALUE;
  }

  int steps = 0;

  while (start != 1)
  {
    if (!(start & 1))
    {
      start = start >> 1;
    }
    else
    {
      start = 3 * start + 1;
    }

    steps++;
  }

  return steps;
}
