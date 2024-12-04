// Calculate Running Sum
// Time Complexity O(n) 0ms
// Space Complexity O(1)

export default function runningSum(nums: number[]): number[] {
  for (let index = 1; index < nums.length; index++) {
    nums[index] += nums[index - 1];
  }

  return nums;
}

// Calculate Running Sum
// Time Complexity O(n) 0ms
// Space Complexity O(n)

export function runningSum01(nums: number[]): number[] {
  let sum = 0;
  return nums.map(num => (sum += num));
}

// Calculate Running Sum
// Time Complexity O(n) 2ms
// Space Complexity O(n)

export function runningSum02(nums: number[]): number[] {
  return nums.reduce((acc, num, i) => {
    acc[i] = num + (acc[i - 1] ?? 0);
    return acc;
  }, []);
}

// Calculate Running Sum
// Time Complexity O(n^2) 3ms
// Space Complexity O(n)

export function runningSum03(nums: number[]): number[] {
  let output = [];

  for (let i = 0; i < nums.length; i++) {
    output[i] = nums[i];

    for (let j = 0; j < i; j++) {
      output[i] += nums[j];
    }
  }

  return output;
}

// Calculate Running Sum
// Time Complexity O(n^2) 4ms - 5ms
// Space Complexity O(n)

export function runningSum04(nums: number[]): number[] {
  return nums.map((_num, index) =>
    nums.slice(0, index + 1).reduce((acc, num) => acc + num, 0)
  );
}
