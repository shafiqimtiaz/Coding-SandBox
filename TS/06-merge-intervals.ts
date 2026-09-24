// Run: npm run code -- 06-merge-intervals.ts
export {};

// First thought: SORT BY START. Time O(n log n), space O(n) for output.

function merge(intervals: number[][]): number[][] {
  intervals.sort((a, b) => a[0] - b[0]);
  const result: number[][] = [];
  for (const interval of intervals) {
    const last = result[result.length - 1];
    if (!last || last[1] < interval[0]) {
      result.push(interval);
    } else {
      last[1] = Math.max(last[1], interval[1]);
    }
  }
  return result;
}

function main(): void {
  console.log(
    merge([
      [1, 3],
      [2, 6],
      [8, 10],
      [15, 18],
    ]),
  ); // [[1,6],[8,10],[15,18]]
  console.log(
    merge([
      [1, 4],
      [4, 5],
    ]),
  ); // [[1,5]]
}

main();
