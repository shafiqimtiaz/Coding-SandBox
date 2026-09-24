// Run: npm run code -- 04-product-except-self.ts
export {};

// Pattern: "everything before i" / "everything after i".
// Product of Array Except Self. Time O(n), extra space O(1) excluding output.

function productExceptSelf(nums: number[]): number[] {
  const result = new Array<number>(nums.length).fill(1);
  let prefix = 1;
  for (let i = 0; i < nums.length; i++) {
    result[i] = prefix;
    prefix *= nums[i];
  }
  let suffix = 1;
  for (let i = nums.length - 1; i >= 0; i--) {
    result[i] *= suffix;
    suffix *= nums[i];
  }
  return result;
}

function main(): void {
  console.log(productExceptSelf([1, 2, 3, 4])); // [24,12,8,6]
  console.log(productExceptSelf([-1, 1, 0, -3, 3])); // [0,0,9,0,0]
}

main();
