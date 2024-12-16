// Rotate 2D Array Counter Clockwise
// Time Complexity  -  O(m + n)
// Space Complexity -  O(1)

export default function rotateCounterClockwise(matrix: number[][]) {
  const length = matrix.length;

  for (let i = 0; i < length; i++) {
    for (let j = i; j < length; j++) {
      [matrix[i][j], matrix[j][i]] = [matrix[j][i], matrix[i][j]];
    }
  }

  return matrix.reverse();
}
