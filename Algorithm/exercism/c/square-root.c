int square_root(int num);

int square_root(int num)
{
  int square_root = 1;

  for (int i = 1; square_root <= num; i++)
  {
    if (square_root == num)
    {
      return i;
    }

    square_root = (i + 1) * (i + 1);
  }

  return -1;
}
