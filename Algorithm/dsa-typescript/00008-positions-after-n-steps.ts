//A robot is standing at the origin of the infinite two-dimensional plane. Each second the robot moves exactly 1 meter in one of the four cardinal directions: north, south, west, and east. For the first step the robot can choose any of the four directions, but then at the end of every second it has to turn 90 degrees left or right with respect to the direction it just moved in. For example, if the robot has just moved north or south, the next step it takes has to be either west or east, and vice versa.
// Time Complexity O(2 ^ n)
// Space Complexity O(n)

export default function possiblePositions(steps: number) {
  const positions = new Set();

  const directions = [
    [1, 0], // East
    [0, -1], // South
    [-1, 0], // West
    [0, 1] // North
  ];

  function move(x: number, y: number, direction: number, steps: number) {
    if (!steps) {
      return positions.add(`${x}, ${y}`);
    }

    const X = x + directions[direction][0];
    const Y = y + directions[direction][1];

    move(X, Y, (direction + 1) % 4, steps - 1); // Turn right
    move(X, Y, (direction + 3) % 4, steps - 1); // Turn left
  }

  for (let i = 0; i < 4; i++) {
    move(0, 0, i, steps);
  }

  return positions.size;
}
