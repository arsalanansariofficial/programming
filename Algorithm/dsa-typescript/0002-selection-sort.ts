// Sort an array
// Time Complexity O(n^2)
// Space Complexity O(1)

export default function selectionSort(array: number[]) {
  const arrayLength = array.length;

  for (let i = 0; i < arrayLength; i++) {
    let max = 0;
    const end = arrayLength - 1 - i;

    for (let j = 1; j < arrayLength - i; j++) {
      if (array[j] > array[max]) {
        max = j;
      }
    }

    [array[max], array[end]] = [array[end], array[max]];
  }

  return array;
}
