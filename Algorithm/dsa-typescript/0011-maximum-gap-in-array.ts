export default function maximumGap(nums: number[]): number {
  const diff: number[] = [];
  nums.sort((a, b) => a - b);

  for (let i = 0, j = i + 1; i < nums.length && j < nums.length; i++, j++)
    diff.push(nums[j] - nums[i]);

  return diff.length && diff.sort((a, b) => b - a)[0];
}
