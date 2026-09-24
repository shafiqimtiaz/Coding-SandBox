// Run: npm run code -- 20-queue-bfs.ts
export {};

// Avoid queue.shift() (O(n)) — push + head pointer instead.
// Time O(V + E), space O(V).

function bfsOrder(adj: Map<number, number[]>, start: number): number[] {
  const queue: number[] = [start];
  let head = 0;
  const seen = new Set<number>([start]);
  const order: number[] = [];
  while (head < queue.length) {
    const v = queue[head++];
    order.push(v);
    for (const n of adj.get(v) ?? []) {
      if (!seen.has(n)) {
        seen.add(n);
        queue.push(n);
      }
    }
  }
  return order;
}

function main(): void {
  const adj = new Map<number, number[]>([
    [0, [1, 2]],
    [1, [0, 3]],
    [2, [0, 3]],
    [3, [1, 2]],
  ]);
  console.log(bfsOrder(adj, 0)); // [0, 1, 2, 3]

  // Coordinates flavor:
  const queue: [number, number][] = [];
  let head = 0;
  queue.push([0, 0]);
  while (head < queue.length) {
    const [r, c] = queue[head++];
    console.log("cell:", r, c);
  }
}

main();
