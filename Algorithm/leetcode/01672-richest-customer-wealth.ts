// Richest Customer Wealth
// Time Complexity O(m * n) 0ms
// Space Complexity O(1) ms

export default function maximumWeatlth(accounts: number[][]): number {
  let maximumWealth = 0;

  accounts.forEach(account => {
    const wealth = account.reduce((acc, wealth) => {
      return acc + wealth;
    }, 0);

    if (wealth > maximumWealth) {
      maximumWealth = wealth;
    }
  });

  return maximumWealth;
}
