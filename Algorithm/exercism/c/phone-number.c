#include <stdlib.h>
#include <string.h>

char *phone_number_clean(const char *input);

char *phone_number_clean(const char *input)
{
  size_t i = 0, nums_len = 0;
  int is_valid_cc = 0, is_valid_ac = 0, is_valid_ec = 0;

  char *output = calloc(11, sizeof(char));
  char *invalid = calloc(11, sizeof(char));
  char *nums = calloc(strlen(input) + 1, sizeof(char));

  for (size_t i = 0; i < 10; i++)
  {
    invalid[i] = '0';
  }

  for (size_t i = 0; input[i]; i++)
  {
    char ch = input[i];

    if (ch >= '0' && ch <= '9')
    {
      nums[nums_len++] = ch;
    }
  }

  if (nums_len < 10 || nums_len > 11)
  {
    return invalid;
  }

  i = nums_len == 10 ? 0 : 1;
  is_valid_cc = nums[0] == '1';

  is_valid_ac = nums[i] != '0' && nums[i] != '1';
  is_valid_ec = nums[i + 3] != '0' && nums[i + 3] != '1';

  if (nums_len == 10 && is_valid_ac && is_valid_ec)
  {
    strncpy(output, nums, 10 * sizeof(char));
    free(nums);
    return output;
  }

  if (nums_len == 11 && is_valid_cc && is_valid_ac && is_valid_ec)
  {
    strncpy(output, nums + 1, 10 * sizeof(char));
    free(nums);
    return output;
  }

  return invalid;
}
