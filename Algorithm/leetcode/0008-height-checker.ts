// Returns indices which have different values
// Time Complexity (n log(n))
// Space Complexity (n)

export default function heightChecker(heights: number[]): number {
  let indices = 0;
  const heights_asc = heights.slice().sort((h1, h2) => h1 - h2);

  heights.forEach((height, index) => {
    if (height != heights_asc[index]) {
      indices++;
    }
  });

  return indices;
}
