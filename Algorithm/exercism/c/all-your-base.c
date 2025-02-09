#include <stdint.h>
#include <stddef.h>

#define DIGITS_ARRAY_SIZE 64

size_t rebase(int8_t digits[], int input_base, int output_base, size_t input_length);

size_t rebase(int8_t digits[], int input_base, int output_base, size_t input_length)
{
  if (!input_length || input_base < 2 || output_base < 2)
  {
    return 0;
  }

  int32_t decimal_value = 0;

  for (size_t i = 0; i < input_length; i++)
  {
    if (digits[i] < 0 || digits[i] >= input_base)
    {
      return 0;
    }

    decimal_value = decimal_value * input_base + digits[i];
  }

  size_t output_length = 0;
  int32_t temp_value = decimal_value;

  do
  {
    temp_value /= output_base;
    output_length++;
  } while (temp_value > 0);

  for (size_t i = 0; i < output_length; i++)
  {
    digits[output_length - i - 1] = decimal_value % output_base;
    decimal_value /= output_base;
  }

  return output_length;
}