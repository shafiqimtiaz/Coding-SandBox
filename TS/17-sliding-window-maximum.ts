// Run: npm run code -- 17-sliding-window-maximum.ts
export {};

// Pattern: next/previous greater, max/min in every window.
// Keep indices in decreasing value order: front = largest candidate.
// Avoid deque.shift() (O(n)) — use a head pointer instead.
// Time O(n), space O(k).

function maxSlidingWindow(nums: number[], k: number): number[] {
  const deque: number[] = [];
  let head = 0;
  const res: number[] = [];
  for (let right = 0; right < nums.length; right++) {
    while (
      deque.length > head &&
      nums[deque[deque.length - 1]] <= nums[right]
    ) {
      deque.pop();
    }
    deque.push(right);
    if (deque[head] <= right - k) {
      head++;
    }
    if (right >= k - 1) {
      res.push(nums[deque[head]]);
    }
  }
  return res;
}

function main(): void {
  console.log(maxSlidingWindow([1, 3, -1, -3, 5, 3, 6, 7], 3)); // [3,3,5,5,6,7]
  console.log(maxSlidingWindow([1], 1)); // [1]
}

main();
