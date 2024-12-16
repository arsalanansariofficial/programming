// Print the Fibonacci Number
// Time Complexity  -  O(n)
// Space Complexity -  O(1)

export default function fibonacciNumber(n: number) {
  let a = 0;
  let b = 1;
  let c = n;

  for (let index = 2; index < n; index++) {
    c = a + b;
    a = b;
    b = c;
  }

  return c;
}

// Print the Fibonacci Number
// Time Complexity  -  O(n)
// Space Complexity -  O(n)

export function fibonacciNumber02(n: number) {
  const fibonaccis = [0, 1];

  if (n < 2) {
    return fibonaccis[n - 1];
  }

  for (let index = 2; index < n; index++) {
    fibonaccis.push(fibonaccis[index - 1] + fibonaccis[index - 2]);
  }

  return fibonaccis.at(-1);
}

// Print the Fibonacci Number
// Time Complexity  -  O(2^n)
// Space Complexity -  O(n)

export function fibonacciNumber03(n: number) {
  if (n < 2) {
    return n;
  }

  return fibonacciNumber03(n - 1) + fibonacciNumber03(n - 2);
}
