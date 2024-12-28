#include <stdint.h>

#define COLORS \
  BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE

typedef enum
{
  COLORS
} resistor_band_t;

uint16_t color_code(resistor_band_t *colors);

uint16_t color_code(resistor_band_t *colors)
{
  return (colors[0] * 10) + colors[1];
}
