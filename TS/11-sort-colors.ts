// Run: npm run code -- 11-sort-colors.ts
export {};

// Dutch National Flag: [0s][unexplored][2s], mid/high pointers.
// 0 -> swap low,mid; low++; mid++ | 1 -> mid++ | 2 -> swap mid,high; high--
// Never increment mid after swapping with high (new nums[mid] uninspected).
// Time O(n), space O(1).

function sortColors(nums: number[]): void {
  let low = 0;
  let mid = 0;
  let high = nums.length - 1;
  while (mid <= high) {
    if (nums[mid] === 0) {
      [nums[low], nums[mid]] = [nums[mid], nums[low]];
      low++;
      mid++;
    } else if (nums[mid] === 1) {
      mid++;
    } else {
      [nums[mid], nums[high]] = [nums[high], nums[mid]];
      high--;
    }
  }
}

function main(): void {
  const a = [2, 0, 2, 1, 1, 0];
  sortColors(a);
  console.log(a); // [0,0,1,1,2,2]
}

main();
