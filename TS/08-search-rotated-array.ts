// Run: npm run code -- 08-search-rotated-array.ts
export {};

// Key observation: at least one half is always sorted.
// Time O(log n), space O(1).

function search(nums: number[], target: number): number {
  let left = 0;
  let right = nums.length - 1;
  while (left <= right) {
    const mid = left + Math.floor((right - left) / 2);
    if (nums[mid] === target) return mid;
    if (nums[left] <= nums[mid]) {
      // Left half is sorted.
      if (nums[left] <= target && target < nums[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    } else {
      // Right half is sorted.
      if (nums[mid] < target && target <= nums[right]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return -1;
}

function main(): void {
  console.log(search([4, 5, 6, 7, 0, 1, 2], 0)); // 4
  console.log(search([4, 5, 6, 7, 0, 1, 2], 3)); // -1
}

main();
