#include <string.h>

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week, const char *day_of_week);

static const char DAYS_OF_MONTH[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static const char *WEEKS[] = {"first", "second", "third", "fourth", "fifth", "last", "teenth"};

static const char *DAYS[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

static int is_leap_year(int year)
{
  if (year % 400 == 0)
  {
    return 1;
  }

  if (year % 100 == 0)
  {
    return 0;
  }

  if (year % 4 == 0)
  {
    return 1;
  }

  return 0;
}

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week, const char *day_of_week)
{
  int req_day = 0, req_week = 0, start = DAYS_OF_MONTH[month - 1] - 6;

  while (req_day < 7 && strcmp(day_of_week, DAYS[req_day]))
  {
    req_day++;
  }

  while (req_week < 7 && strcmp(week, WEEKS[req_week]))
  {
    req_week++;
  }

  if (!req_week)
  {
    start = 1;
  }

  if (req_week && req_week < 4)
  {
    start = 7 * req_week + 1;
  }

  if (req_week && req_week == 6)
  {
    start = 13;
  }

  if (req_week && month == 2 && is_leap_year(year))
  {
    start += 1;
  }

  int day = start;

  if (month < 3)
  {
    day += year--;
  }

  if (month >= 3)
  {
    day += year - 2;
  }

  int dow = (23 * month / 9 + day + 4 + year / 4 - year / 100 + year / 400) % 7;

  if (dow == req_day)
  {
    return start;
  }

  if (dow < req_day)
  {
    return start + req_day - dow;
  }

  return start + req_day - dow + 7;
}
