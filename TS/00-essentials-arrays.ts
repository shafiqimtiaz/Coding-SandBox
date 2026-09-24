// Run: npm run code -- 00-essentials-arrays.ts
export {};

// Arrays: push/pop, numeric sort, copy, min/max/sum, swap, min/max init.

function main(): void {
  const nums: number[] = [3, 1, 2];
  nums.push(4);
  nums.pop();
  console.log("length:", nums.length);

  // Gotcha: default sort() is lexicographic — always pass a comparator for numbers.
  console.log("asc:", [...nums].sort((a, b) => a - b));
  console.log("desc:", [...nums].sort((a, b) => b - a));

  const copy = [...nums];
  console.log("copy:", copy);
  console.log("min:", Math.min(...nums), "max:", Math.max(...nums));
  console.log("sum:", nums.reduce((a, b) => a + b, 0));

  const arr = [1, 2, 3];
  [arr[0], arr[2]] = [arr[2], arr[0]];
  console.log("swapped:", arr);

  let lo = Infinity;
  let hi = -Infinity;
  for (const n of nums) {
    lo = Math.min(lo, n);
    hi = Math.max(hi, n);
  }
  console.log("lo:", lo, "hi:", hi);
}

main();
