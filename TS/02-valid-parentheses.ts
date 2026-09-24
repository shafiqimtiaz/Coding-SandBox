// Run: npm run code -- 02-valid-parentheses.ts
export {};

// Pattern: matching brackets, nested structure, expression parsing.
// Time O(n), space O(n).

function isValid(s: string): boolean {
  const stack: string[] = [];
  const pairs: Record<string, string> = {
    ")": "(",
    "]": "[",
    "}": "{",
  };
  for (const ch of s) {
    if (!(ch in pairs)) {
      stack.push(ch);
    } else if (stack.pop() !== pairs[ch]) {
      return false;
    }
  }
  return stack.length === 0;
}

function main(): void {
  console.log(isValid("()[]{}")); // true
  console.log(isValid("(]")); // false
  console.log(isValid("([)]")); // false
  console.log(isValid("{[]}")); // true
}

main();
