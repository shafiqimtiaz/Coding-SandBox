// Run: npm run code -- longest-palindromic-substring.ts
export {};

// Expand around center; check odd (aba) and even (abba) centers.
// Time O(n^2), space O(1).

function longestPalindrome(s: string): string {
  if (s.length === 0) return "";
  const expand = (left: number, right: number): number => {
    while (left >= 0 && right < s.length && s[left] === s[right]) {
      left--;
      right++;
    }
    return right - left - 1;
  };
  let start = 0;
  let maxLen = 1;
  for (let i = 0; i < s.length; i++) {
    const odd = expand(i, i);
    const even = expand(i, i + 1);
    const len = Math.max(odd, even);
    if (len > maxLen) {
      maxLen = len;
      start = i - Math.floor((len - 1) / 2);
    }
  }
  return s.slice(start, start + maxLen);
}

function main(): void {
  console.log(longestPalindrome("babad")); // "bab" or "aba"
  console.log(longestPalindrome("cbbd")); // "bb"
}

main();
