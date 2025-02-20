export default function topKFrequent(nums: number[], k: number) {
  const freq: Map<number, number> = new Map();

  nums.forEach((element, index) => {
    if (freq.has(element)) return freq.set(element, freq.get(element) + 1);
    freq.set(element, 1);
  });

  return Array.from(freq)
    .sort((a, b) => b[1] - a[1])
    .map((a, b) => a[0])
    .slice(0, k);
}
