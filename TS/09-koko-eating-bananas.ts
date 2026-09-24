// Run: npm run code -- 09-koko-eating-bananas.ts
export {};

// Pattern: minimum speed/capacity/time that works (monotonic false...false true...true).
// Key question: "If X works, will every larger X also work?" If yes, binary-search it.
// Time O(n log max), space O(1).

function minEatingSpeed(piles: number[], h: number): number {
  const canFinish = (speed: number): boolean => {
    let hours = 0;
    for (const pile of piles) {
      hours += Math.ceil(pile / speed);
    }
    return hours <= h;
  };
  let left = 1;
  let right = Math.max(...piles);
  while (left < right) {
    const mid = left + Math.floor((right - left) / 2);
    if (canFinish(mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

function main(): void {
  console.log(minEatingSpeed([3, 6, 7, 11], 8)); // 4
  console.log(minEatingSpeed([30, 11, 23, 4, 20], 5)); // 30
}

main();
