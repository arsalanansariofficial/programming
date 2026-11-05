// Range Game, hit every alternate target starting from index 0, removing every target after reaching that target. Points are calculated as the label of target. Hit target until the there is only 1 target left (Targets starts from 1 to length).
// Time Complexity O(n log(n))
// Space Complexity O(n)

export default function calculatePoints(length: number) {
  let points = 0;
  let targets = [];

  for (let i = 0; i < length; i++) {
    targets.push(i + 1);
  }

  while (targets.length > 1) {
    const newTargets = [];

    for (let i = 0; i < targets.length; i += 2) {
      points += targets[i];
    }

    for (let i = 1; i < targets.length; i += 2) {
      newTargets.push(targets[i]);
    }

    targets = newTargets;
  }

  return points;
}
