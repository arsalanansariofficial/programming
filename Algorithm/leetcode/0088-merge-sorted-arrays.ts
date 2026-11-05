// Merge two sorted arrays
// 0's in nums1 are placeholder for additional elements
// Example nums1 --> [1, 2, 3, 0, 0, 0] & nums2[4, 5, 6]
// Result --> [1, 2, 3, 4, 5, 6]
// Time Complexity O(m + n)
// Space Complexity O(1)

export default function mergeSortedArray(
  nums1: number[],
  m: number,
  nums2: number[],
  n: number
) {
  let endM = m - 1;
  let endN = n - 1;
  let end = m + n - 1;

  while (endN > -1) {
    if (endN > -1 && nums1[endM] > nums2[endN]) {
      nums1[end--] = nums1[endM--];
      continue;
    }

    nums1[end--] = nums2[endN--];
  }

  return nums1;
}
