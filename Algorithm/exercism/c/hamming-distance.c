int compute(const char *lhs, const char *rhs);

int compute(const char *lhs, const char *rhs)
{
  if (!lhs || !rhs)
  {
    return -1;
  }

  int distance = 0;

  while (*lhs && *rhs)
  {
    if (*lhs != *rhs)
    {
      distance++;
    }

    lhs++;
    rhs++;
  }

  // Checking the length of strings
  if (*lhs != *rhs)
  {
    return -1;
  }

  return distance;
}