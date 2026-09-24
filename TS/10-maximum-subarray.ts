// Run: npm run code -- 10-maximum-subarray.ts
export {};

// Kadane: at each element, start new subarray OR extend previous.
// Time O(n), space O(1).

function maxSubArray(nums: number[]): number {
  let current = nums[0];
  let best = nums[0];
  for (let i = 1; i < nums.length; i++) {
    current = Math.max(nums[i], current + nums[i]);
    best = Math.max(best, current);
  }
  return best;
}

function main(): void {
  console.log(maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4])); // 6
  console.log(maxSubArray([1])); // 1
}

main();
