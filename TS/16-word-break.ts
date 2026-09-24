// Run: npm run code -- 16-word-break.ts
export {};

// DP recipe: state -> recurrence -> base cases -> iteration order -> answer.
// Ask: "Am I solving the same smaller problem repeatedly?"
// Time O(n^2 * m) naive, space O(n).

function wordBreak(s: string, wordDict: string[]): boolean {
  const words = new Set(wordDict);
  const dp = new Array<boolean>(s.length + 1).fill(false);
  dp[0] = true;
  for (let i = 1; i <= s.length; i++) {
    for (let j = 0; j < i; j++) {
      if (dp[j] && words.has(s.slice(j, i))) {
        dp[i] = true;
        break;
      }
    }
  }
  return dp[s.length];
}

function main(): void {
  console.log(wordBreak("leetcode", ["leet", "code"])); // true
  console.log(wordBreak("applepenapple", ["apple", "pen"])); // true
  console.log(wordBreak("catsandog", ["cats", "dog", "sand", "and", "cat"])); // false
}

main();
