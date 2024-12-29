// Return indices of numbers whose sum equals target
// Time Complexity O(n)
// Space Complexity O(n)

export default function twoSum(nums: number[], target: number): number[] {
  const pairs = {};

  for (let i = 0; i < nums.length; i++) {
    const num = nums[i];
    const pair = target - nums[i];
    const complement = pairs[pair];

    if (complement) {
      return [complement, i];
    }

    pairs[num] = i;
  }

  return [];
}
