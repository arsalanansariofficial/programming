unsigned int egg_count(unsigned int display);

unsigned int egg_count(unsigned int display)
{
  unsigned int count = 0;

  while (display)
  {
    count += display & 1;
    display >>= 1;
  }

  return count;
}