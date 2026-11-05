// Find the duplicates in an Array
// Time Complexity  -  O(n^2)
// Space Complexity -  O(1)

export default function findDuplicates(array: number[]) {
  let count = 0;
  const size = array.length;

  for (let i = 0; i < size; i++) {
    for (let j = i + 1; j < size; j++) {
      count++;

      if (array[i] === array[j]) {
        return { i, count };
      }
    }
  }
}

// Find the duplicates in an Array
// Time Complexity  -  O(n)
// Space Complexity -  O(n)

export function findDuplicates01(array: number[]) {
  const size = array.length;
  const count = new Array(100).fill(0);

  for (let i = 0; i < size; i++) {
    count[array[i]]++;

    if (count[array[i]] > 1) {
      return i;
    }
  }
}
