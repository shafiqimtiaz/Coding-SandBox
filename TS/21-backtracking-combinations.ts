// Run: npm run code -- 21-backtracking-combinations.ts
export {};

// Pattern: all combinations / permutations / valid configs.
// Mental model: choose -> explore -> undo.

function combine(n: number, k: number): number[][] {
  const result: number[][] = [];
  const backtrack = (start: number, path: number[]): void => {
    if (path.length === k) {
      result.push([...path]);
      return;
    }
    for (let i = start; i <= n; i++) {
      path.push(i);
      backtrack(i + 1, path);
      path.pop();
    }
  };
  backtrack(1, []);
  return result;
}

function main(): void {
  console.log(combine(4, 2)); // 6 combos
}

main();
