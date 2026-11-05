// Sort an array
// Time Complexity O(n^2)
// Space Complexity O(1)

export default function bubbleSort(array: number[]) {
  for (let i = 0; i < array.length; i++) {
    for (let j = 1; j < array.length - i; j++) {
      if (array[j - 1] > array[j]) {
        [array[j - 1], array[j]] = [array[j], array[j - 1]];
      }
    }
  }

  return array;
}
