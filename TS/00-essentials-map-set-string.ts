// Run: npm run code -- 00-essentials-map-set-string.ts
export {};

// Map / Set / strings / ?? vs || / === / number limits.

function main(): void {
  const nums = [1, 2, 2, 3, 3, 3];

  const freq = new Map<number, number>();
  for (const n of nums) {
    freq.set(n, (freq.get(n) ?? 0) + 1);
  }
  console.log("freq:", [...freq.entries()]);

  const seen = new Set<number>();
  seen.add(5);
  console.log("has 5:", seen.has(5));
  console.log("unique:", [...new Set(nums)]);

  const s = "Hello World";
  console.log("len:", s.length, "char:", s[1], "slice:", s.slice(0, 5));
  console.log("lower:", s.toLowerCase());
  console.log("sorted chars:", [..."cba"].sort().join(""));

  // ?? instead of || : 0 is a valid value, don't fall through on it.
  const m = new Map<string, number>([["a", 0]]);
  console.log("?? keeps 0:", m.get("a") ?? 99);

  // Strict equality, number limits.
  console.log("strict eq:", (1 as unknown) === (1 as unknown));
  console.log("MAX_SAFE_INTEGER:", Number.MAX_SAFE_INTEGER);
}

main();
