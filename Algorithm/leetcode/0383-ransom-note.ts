// Ransom Note
// Check if 'ransomNote' can be constructed by using the letters from 'magazine'
// Each letter in magazine can only be used once in ransomNote
// Time Complexity O(n)
// Space Complexity O(k (log n))
// where k = number of distinct characters in magazine
// n = length of magazine

export default function canConstruct(
  ransomNote: string,
  magazine: string
): boolean {
  const dictionary = new Map<string, number>();

  for (let index = 0; index < magazine.length; index++) {
    const char = magazine[index];
    const currentCount = dictionary.get(char) || 0;

    dictionary.set(char, currentCount + 1);
  }

  for (let index = 0; index < ransomNote.length; index++) {
    const char = ransomNote[index];
    const currentCount = dictionary.get(char) || 0;

    if (!currentCount) {
      return false;
    }

    dictionary.set(char, dictionary.get(char) - 1);
  }

  return true;
}
