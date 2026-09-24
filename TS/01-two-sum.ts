// Run: npm run code -- 01-two-sum.ts
export {};

// Pattern: fast lookup / frequency / complements / "have I seen this before?"
// Time O(n), space O(n).

function twoSum(nums: number[], target: number): number[] {
  const seen = new Map<number, number>();
  for (let i = 0; i < nums.length; i++) {
    const need = target - nums[i];
    if (seen.has(need)) {
      return [seen.get(need)!, i];
    }
    seen.set(nums[i], i);
  }
  return [];
}

function main(): void {
  console.log(twoSum([2, 7, 11, 15], 9)); // [0, 1]
  console.log(twoSum([3, 2, 4], 6)); // [1, 2]
}

main();
