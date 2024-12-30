#define INVALID -1

int convert(const char *input);

int convert(const char *input)
{
  int decimal = 0;

  for (char *i = (char *)input; *i; i++)
  {
    if (*i != '0' && *i != '1')
    {
      return INVALID;
    }

    decimal = decimal * 2 + (*i == '0' ? 0 : 1);
  }

  return decimal;
}