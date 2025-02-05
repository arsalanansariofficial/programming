#include <stdio.h>

typedef int resistor_band_t;

typedef enum
{
  OHMS = 1,
  KILOOHMS = 1000,
  MEGAOHMS = 1000000,
  GIGAOHMS = 1000000000
} Unit;

typedef struct resistor_value_t
{
  long long value;
  long long unit;
} resistor_value_t;

enum
{
  BLACK,
  BROWN,
  RED,
  ORANGE,
  YELLOW,
  GREEN,
  BLUE,
  VIOLET,
  GREY,
  WHITE
};

resistor_value_t color_code(resistor_band_t bands[]);

resistor_value_t color_code(resistor_band_t bands[])
{
  resistor_value_t resistor = {0, OHMS};

  for (int i = 0; i < 2; i++)
  {
    resistor.value = resistor.value * 10 + bands[i];
  }

  for (int i = 0; i < bands[2]; i++)
  {
    resistor.value *= 10;
  }

  if (resistor.value >= GIGAOHMS)
  {
    resistor.value /= GIGAOHMS;
    resistor.unit = GIGAOHMS;
  }

  if (resistor.value >= MEGAOHMS)
  {
    resistor.value /= MEGAOHMS;
    resistor.unit = MEGAOHMS;
  }

  if (resistor.value >= KILOOHMS)
  {
    resistor.value /= KILOOHMS;
    resistor.unit = KILOOHMS;
  }

  return resistor;
}
