#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

int compare(const void *a, const void *b);
int32_t latest(const int32_t *scores, size_t scores_len);

int32_t personal_best(const int32_t *scores, size_t scores_len);
size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output);

int compare(const void *a, const void *b)
{
  return (*(int *)b - *(int *)a);
}

int32_t latest(const int32_t *scores, size_t scores_len)
{
  return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len)
{
  qsort((int32_t *)scores, scores_len, sizeof(int32_t), compare);
  return scores[0];
}

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output)
{
  qsort((int32_t *)scores, scores_len, sizeof(int32_t), compare);

  if (scores_len > 3)
  {
    scores_len = 3;
  }

  for (size_t i = 0; i < scores_len; i++)
  {
    output[i] = scores[i];
  }

  return scores_len;
}