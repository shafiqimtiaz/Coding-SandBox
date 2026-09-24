// Run: npm run code -- sliding-window.ts
export {};

// Pattern: substring / subarray / contiguous / longest / shortest / at most K.
// Mental model: expand right -> shrink left while invalid -> record answer.
// Time O(n), space O(charset).

function lengthOfLongestSubstring(s: string): number {
  const last = new Map<string, number>();
  let left = 0;
  let answer = 0;
  for (let right = 0; right < s.length; right++) {
    if (last.has(s[right]) && last.get(s[right])! >= left) {
      left = last.get(s[right])! + 1;
    }
    last.set(s[right], right);
    answer = Math.max(answer, right - left + 1);
  }
  return answer;
}

function main(): void {
  console.log(lengthOfLongestSubstring("abcabcbb")); // 3
  console.log(lengthOfLongestSubstring("bbbbb")); // 1
  console.log(lengthOfLongestSubstring("pwwkew")); // 3
}

main();
