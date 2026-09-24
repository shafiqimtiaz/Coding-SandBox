// Run: npm run code -- 15-lru-cache.ts
export {};

// Design: HashMap + recency order. JS Map preserves insertion order, so
// delete + set moves a key to front (most recent); first key is LRU.
// get/put are O(1) average. (Classic variant uses HashMap + doubly linked list.)

class LRUCache {
  private cap: number;
  private cache = new Map<number, number>();

  constructor(capacity: number) {
    this.cap = capacity;
  }

  get(key: number): number {
    if (!this.cache.has(key)) return -1;
    const value = this.cache.get(key)!;
    this.cache.delete(key);
    this.cache.set(key, value);
    return value;
  }

  put(key: number, value: number): void {
    if (this.cache.has(key)) {
      this.cache.delete(key);
    } else if (this.cache.size >= this.cap) {
      const lru = this.cache.keys().next().value!;
      this.cache.delete(lru);
    }
    this.cache.set(key, value);
  }
}

function main(): void {
  const c = new LRUCache(2);
  c.put(1, 1);
  c.put(2, 2);
  console.log(c.get(1)); // 1
  c.put(3, 3); // evicts 2
  console.log(c.get(2)); // -1
  c.put(4, 4); // evicts 1
  console.log(c.get(1)); // -1
  console.log(c.get(3)); // 3
  console.log(c.get(4)); // 4
}

main();
