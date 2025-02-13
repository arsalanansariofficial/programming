#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_paired(const char *input);

bool is_paired(const char *input)
{
  int top = 0;
  char stack[strlen(input) + 1];

  for (int i = 0; input[i]; i++)
  {
    char ch = input[i];

    if (ch == '(' || ch == '{' || ch == '[')
    {
      stack[top++] = ch;
      continue;
    }

    if (ch == ')' || ch == '}' || ch == ']')
    {
      if (!top)
      {
        return 0;
      }

      char popped_char = stack[--top];
      int not_balenced_curly = ch == '}' && popped_char != '{';
      int not_balenced_square = ch == ']' && popped_char != '[';
      int not_balenced_parens = ch == ')' && popped_char != '(';

      if (not_balenced_curly || not_balenced_square || not_balenced_parens)
      {
        return 0;
      }
    }
  }

  return !top;
}