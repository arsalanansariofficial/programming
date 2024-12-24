#include "stdlib.h"
#include "stdbool.h"
#include <stdint.h>

typedef enum
{
  CAN_NOT_ATTACK,
  CAN_ATTACK,
  INVALID_POSITION
} attack_status_t;

typedef struct
{
  uint8_t row;
  uint8_t column;
} position_t;

attack_status_t can_attack(position_t queen_1, position_t queen_2);

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
  bool queen_1_has_row_col = queen_1.row < 8 && queen_1.column < 8;
  bool queen_2_has_row_col = queen_2.row < 8 && queen_2.column < 8;
  bool same_position = (queen_1.row == queen_2.row) && (queen_1.column == queen_2.column);

  if (!queen_1_has_row_col || !queen_2_has_row_col || same_position)
  {
    return INVALID_POSITION;
  }

  if (queen_1.row == queen_2.row)
  {
    return CAN_ATTACK;
  }

  if (queen_1.column == queen_2.column)
  {
    return CAN_ATTACK;
  }

  if (abs(queen_1.row - queen_2.row) == abs(queen_1.column - queen_2.column))
  {
    return CAN_ATTACK;
  }

  return CAN_NOT_ATTACK;
}