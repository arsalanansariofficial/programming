// Sort an array
// Time Complexity O(n^2)
// Space Complexity O(1)

export default function insertionSort(array: number[]) {
  for (let i = 1; i < array.length; i++) {
    let j = i;

    while (j > 0 && array[j - 1] > array[j]) {
      [array[j - 1], array[j]] = [array[j], array[j - 1]];
      j--;
    }
  }

  return array;
}
