// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// Time Complexity O(n)
// Space Complexity O(1)

export default function sortColors(nums: number[]) {
  const counts = [0, 0, 0];

  nums.forEach(num => counts[num]++);

  for (let i = 0; i < nums.length; i++) {
    if (counts[0]) {
      nums[i] = 0;
      counts[0]--;
      continue;
    }

    if (counts[1]) {
      nums[i] = 1;
      counts[1]--;
      continue;
    }

    if (counts[2]) {
      nums[i] = 2;
      counts[2]--;
      continue;
    }
  }

  return nums;
}
