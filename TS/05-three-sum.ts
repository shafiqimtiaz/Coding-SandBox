// Run: npm run code -- 05-three-sum.ts
export {};

// Pattern: sorted array, pair/triplet, palindrome, dedupe.
// 3Sum time O(n^2), space O(1) excluding output.

function hasPairSum(sorted: number[], target: number): boolean {
  let left = 0;
  let right = sorted.length - 1;
  while (left < right) {
    const sum = sorted[left] + sorted[right];
    if (sum === target) {
      return true;
    }
    if (sum < target) {
      left++;
    } else {
      right--;
    }
  }
  return false;
}

function threeSum(nums: number[]): number[][] {
  const res: number[][] = [];
  nums.sort((a, b) => a - b);
  for (let i = 0; i < nums.length - 2; i++) {
    if (i > 0 && nums[i] === nums[i - 1]) continue;
    let left = i + 1;
    let right = nums.length - 1;
    while (left < right) {
      const sum = nums[i] + nums[left] + nums[right];
      if (sum < 0) {
        left++;
      } else if (sum > 0) {
        right--;
      } else {
        res.push([nums[i], nums[left], nums[right]]);
        left++;
        right--;
        while (left < right && nums[left] === nums[left - 1]) left++;
        while (left < right && nums[right] === nums[right + 1]) right--;
      }
    }
  }
  return res;
}

function main(): void {
  console.log(hasPairSum([1, 2, 4, 6, 8], 10)); // true
  console.log(threeSum([-1, 0, 1, 2, -1, -4])); // [[-1,-1,2],[-1,0,1]]
}

main();
