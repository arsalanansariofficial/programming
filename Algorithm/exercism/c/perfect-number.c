typedef enum
{
  ERROR = -1,
  PERFECT_NUMBER = 1,
  ABUNDANT_NUMBER = 2,
  DEFICIENT_NUMBER = 3,
} kind;

int classify_number(int number);

int classify_number(int number)
{
  if (number < 1)
  {
    return ERROR;
  }

  int aliquot_sum = 0;

  for (int i = 1; i < number; i++)
  {
    if (!(number % i))
    {
      aliquot_sum += i;
    }
  }

  if (number == aliquot_sum)
  {
    return PERFECT_NUMBER;
  }

  if (number < aliquot_sum)
  {
    return ABUNDANT_NUMBER;
  }

  return DEFICIENT_NUMBER;
}
