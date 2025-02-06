#include <time.h>

void gigasecond(time_t input, char *output, size_t size);

void gigasecond(time_t input, char *output, size_t size)
{
  time_t giga_second = input + 1000000000;
  struct tm *time_info = gmtime(&giga_second);
  strftime(output, size, "%Y-%m-%d %H:%M:%S", time_info);
}