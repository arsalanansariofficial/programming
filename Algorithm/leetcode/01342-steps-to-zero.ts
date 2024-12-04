// Calculate number of steps required to reduce a number to zero
// If num is even divide it by 2
// If num is odd subtract 1 from it

// Time Complexity O(log n) ms
// Space Complexity O(1)

export default function numberOfSteps(num: number): number {
  let steps = 0;

  while (num > 0) {
    if (num % 2 === 0) {
      num /= 2;
    } else {
      num--;
    }

    steps++;
  }

  return steps;
}

// Time Complexity O(log n) ms
// Space Complexity O(1)

export function numberOfSteps01(num: number): number {
  let steps = 0;

  while (num > 0) {
    if ((num & 1) === 0) {
      num >>= 1;
    } else {
      num--;
    }

    steps++;
  }

  return steps;
}
