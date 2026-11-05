export default function smallestTrimmedNumbers(
  nums: string[],
  queries: number[][]
): number[] {
  const results: number[] = [];

  for (const [k, trim] of queries) {
    const trimmedNums = nums.map(num => num.slice(-trim));
    const indices = trimmedNums.map((_, index) => index);

    indices.sort((a, b) => {
      if (trimmedNums[a] < trimmedNums[b]) return -1;
      if (trimmedNums[a] === trimmedNums[b]) return 0;
      return 1;
    });

    results.push(indices[k - 1]);
  }

  return results;
}
