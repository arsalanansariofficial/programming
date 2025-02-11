#include <math.h>
#include <stdlib.h>

#include <stdint.h>

typedef struct
{
  int numerator;
  int denominator;
} rational_t;

rational_t add(rational_t a, rational_t b);
rational_t subtract(rational_t a, rational_t b);
rational_t multiply(rational_t a, rational_t b);
rational_t divide(rational_t a, rational_t b);

rational_t reduce(rational_t r);
rational_t reduced(int numerator, int denominator);

rational_t absolute(rational_t r);
float exp_real(uint16_t x, rational_t r);
rational_t exp_rational(rational_t r, int16_t x);

rational_t add(rational_t a, rational_t b)
{
  return reduced(a.numerator * b.denominator + b.numerator * a.denominator, a.denominator * b.denominator);
}

rational_t subtract(rational_t a, rational_t b)
{
  return reduced(a.numerator * b.denominator - b.numerator * a.denominator, a.denominator * b.denominator);
}

rational_t multiply(rational_t a, rational_t b)
{
  return reduced(a.numerator * b.numerator, a.denominator * b.denominator);
}

rational_t divide(rational_t a, rational_t b)
{
  return reduced(a.numerator * b.denominator, b.numerator * a.denominator);
}

rational_t reduce(rational_t r)
{
  return reduced(r.numerator, r.denominator);
}

rational_t reduced(int numerator, int denominator)
{
  int n = abs(numerator), d = abs(denominator);

  while ((n %= d) && (d %= n))
    ;

  int gcd = (n | d) * (denominator < 0 ? -1 : 1);
  return (rational_t){numerator / gcd, denominator / gcd};
}

rational_t absolute(rational_t r)
{
  return reduced(abs(r.numerator), abs(r.denominator));
}

#include <stdio.h>

rational_t exp_rational(rational_t r, int16_t x)
{
  if (x >= 0)
  {
    return reduced(pow(r.numerator, x), pow(r.denominator, x));
  }

  return reduced((float)(pow(r.denominator, abs(x))), (float)(pow(r.numerator, abs(x))));
}

float exp_real(uint16_t x, rational_t r)
{
  return powf(x, r.numerator / (float)r.denominator);
}