#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
  char text[15];
} clock_t;

int normalize_minutes(int minutes);
clock_t get_clock(int minutes);

int get_minutes_from_text(char text[]);
clock_t clock_create(int hour, int minute);

clock_t clock_add(clock_t clock, int minute_add);
clock_t clock_subtract(clock_t clock, int minute_subtract);

bool clock_is_equal(clock_t a, clock_t b);

#define HOUR_MINUTES 60
#define DAYS_MINUTES 1440

int normalize_minutes(int minutes)
{
  if (minutes < 0)
  {
    return DAYS_MINUTES + (minutes % DAYS_MINUTES);
  }

  return minutes % DAYS_MINUTES;
}

clock_t get_clock(int minutes)
{
  clock_t clock;

  int hour = minutes / HOUR_MINUTES;
  int remaining_minute = minutes % HOUR_MINUTES;

  sprintf(clock.text, "%02d:%02d", hour, remaining_minute);
  return clock;
}

int get_minutes_from_text(char text[])
{
  int hour, minute;
  sscanf(text, "%d:%d", &hour, &minute);
  return hour * HOUR_MINUTES + minute;
}

clock_t clock_create(int hour, int minute)
{
  return get_clock(normalize_minutes(hour * HOUR_MINUTES + minute));
}

clock_t clock_add(clock_t clock, int minute_add)
{
  return clock_create(0, get_minutes_from_text(clock.text) + minute_add);
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
  return clock_create(0, get_minutes_from_text(clock.text) - minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b)
{
  return !strcmp(a.text, b.text);
}