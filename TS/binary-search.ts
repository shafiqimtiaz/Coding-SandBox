// Run: npm run code -- binary-search.ts
export {};

// Pattern: sorted data, exact position or boundary.
// Time O(log n), space O(1).

function binarySearch(nums: number[], target: number): number {
  let left = 0;
  let right = nums.length - 1;
  while (left <= right) {
    const mid = left + Math.floor((right - left) / 2);
    if (nums[mid] === target) {
      return mid;
    }
    if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

function main(): void {
  console.log(binarySearch([-1, 0, 3, 5, 9, 12], 9)); // 4
  console.log(binarySearch([-1, 0, 3, 5, 9, 12], 2)); // -1
}

main();
