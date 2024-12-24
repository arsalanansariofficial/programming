#define COLORS \
  BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE

typedef enum
{
  COLORS
} resistor_band_t;

resistor_band_t *colors(void);
int color_code(resistor_band_t color);

int color_code(resistor_band_t name)
{
  return name;
}

resistor_band_t *colors(void)
{
  static resistor_band_t resistor_colors[] = {COLORS};
  return resistor_colors;
}