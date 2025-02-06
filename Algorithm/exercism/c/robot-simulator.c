typedef struct
{
  int x;
  int y;
} robot_position_t;

typedef enum
{
  DIRECTION_NORTH,
  DIRECTION_EAST,
  DIRECTION_SOUTH,
  DIRECTION_WEST,
} robot_direction_t;

typedef struct
{
  robot_direction_t direction;
  robot_position_t position;
} robot_status_t;

robot_status_t robot_create(robot_direction_t direction, int x, int y);
void robot_move(robot_status_t *robot, const char *commands);

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
  return (robot_status_t){direction, {x, y}};
}

void robot_move(robot_status_t *robot, const char *commands)
{
  robot_position_t NORTH = {0, 1};
  robot_position_t EAST = {1, 0};

  robot_position_t SOUTH = {0, -1};
  robot_position_t WEST = {-1, 0};

  for (int i = 0; commands[i]; i++)
  {
    if (commands[i] == 'R')
    {
      robot->direction = (robot->direction + 1) % 4;
      continue;
    }

    if (commands[i] == 'L')
    {
      robot->direction = (robot->direction + 3) % 4;
      continue;
    }

    if (robot->direction == DIRECTION_NORTH)
    {
      robot->position.x += NORTH.x;
      robot->position.y += NORTH.y;
      continue;
    }

    if (robot->direction == DIRECTION_EAST)
    {
      robot->position.x += EAST.x;
      robot->position.y += EAST.y;
      continue;
    }

    if (robot->direction == DIRECTION_SOUTH)
    {
      robot->position.x += SOUTH.x;
      robot->position.y += SOUTH.y;
      continue;
    }

    if (robot->direction == DIRECTION_WEST)
    {
      robot->position.x += WEST.x;
      robot->position.y += WEST.y;
      continue;
    }
  }
}
