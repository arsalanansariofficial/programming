#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 16

char *to_roman_numeral(unsigned int number);

char *to_roman_numeral(unsigned int num)
{
  char *roman_number = calloc(MAX_LENGTH, sizeof(char));

  char *ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
  char *tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
  char *hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
  char *thousands[] = {"", "M", "MM", "MMM"};

  sprintf(roman_number, "%s%s%s%s", thousands[num / 1000 % 10], hundreds[num / 100 % 10], tens[num / 10 % 10], ones[num % 10]);

  return roman_number;
}
