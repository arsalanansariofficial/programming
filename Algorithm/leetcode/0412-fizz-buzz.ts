// Fizz-Buzz Game
// Time Complexity O(n) 0ms
// Space Complexity O(n)

export default function fizzBuzz(n: number): string[] {
  const answer = [];

  for (let index = 1; index <= n; index++) {
    let string = String();

    const divisibleBy3 = index % 3 === 0;
    const divisibleBy5 = index % 5 === 0;

    if (divisibleBy3) {
      string = string.concat('Fizz');
    }

    if (divisibleBy5) {
      string = string.concat('Buzz');
    }

    if (!string) {
      string = string.concat(String(index));
    }

    answer.push(string);
  }

  return answer;
}
