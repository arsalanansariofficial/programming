#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXERR 100

typedef struct factors_t
{
  int factor_a;
  int factor_b;
  struct factors_t *next;
} factor_t;

typedef struct product_t
{
  int smallest;
  int largest;
  factor_t *factors_sm;
  factor_t *factors_lg;
  char error[MAXERR];
} product_t;

factor_t *clear_factors(factor_t *factors);
void add_factor(factor_t **prev, int a, int b);

bool is_palindrome(int value);
void free_product(product_t *p);
product_t *get_palindrome_product(int from, int to);

factor_t *clear_factors(factor_t *factors)
{
  if (!factors)
  {
    return NULL;
  }

  clear_factors(factors->next);
  free(factors);
  return NULL;
}

void add_factor(factor_t **prev, int a, int b)
{
  factor_t *factors = malloc(sizeof(factor_t));

  factors->factor_a = a;
  factors->factor_b = b;
  factors->next = *prev;

  *prev = factors;
}

bool is_palindrome(int value)
{
  int num = value, reversed = 0;

  while (num)
  {
    reversed = reversed * 10 + num % 10;
    num /= 10;
  }

  return value == reversed;
}

void free_product(product_t *product)
{
  clear_factors(product->factors_lg);
  clear_factors(product->factors_sm);
  free(product);
}

product_t *get_palindrome_product(int from, int to)
{
  product_t *product = calloc(1, sizeof(product_t));

  for (int i = from; i <= to; i++)
  {
    for (int j = i; j <= to; j++)
    {
      int num = i * j;

      if (!is_palindrome(num))
      {
        continue;
      }

      if (!product->smallest)
      {
        product->smallest = product->largest = num;
        add_factor(&product->factors_sm, i, j);
        add_factor(&product->factors_lg, i, j);
        continue;
      }

      if (num == product->largest)
      {
        add_factor(&product->factors_lg, i, j);
        continue;
      }

      if (num > product->largest)
      {
        product->largest = num;
        product->factors_lg = clear_factors(product->factors_lg);
        add_factor(&product->factors_lg, i, j);
        continue;
      }

      if (num == product->smallest)
      {
        add_factor(&product->factors_sm, i, j);
        continue;
      }

      if (num < product->smallest)
      {
        product->smallest = num;
        product->factors_sm = clear_factors((product->factors_sm));
        add_factor(&product->factors_sm, i, j);
        continue;
      }
    }
  }

  if (!product->smallest || !product->largest)
  {
    sprintf(product->error, "no palindrome with factors in the range %i to %i", from, to);
  }

  if (from > to)
  {
    sprintf(product->error, "invalid input: min is %i and max is %i", from, to);
  }

  return product;
}