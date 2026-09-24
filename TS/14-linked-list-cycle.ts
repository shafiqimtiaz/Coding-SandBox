// Run: npm run code -- 14-linked-list-cycle.ts
export {};

// Pattern: cycle / middle / entry — slow +1, fast +2.
// Time O(n), space O(1).

class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val = 0, next: ListNode | null = null) {
    this.val = val;
    this.next = next;
  }
}

function hasCycle(head: ListNode | null): boolean {
  let slow = head;
  let fast = head;
  while (fast && fast.next) {
    slow = slow!.next;
    fast = fast.next.next;
    if (slow === fast) {
      return true;
    }
  }
  return false;
}

function main(): void {
  const a = new ListNode(1, new ListNode(2, new ListNode(3)));
  console.log(hasCycle(a)); // false
  const cyc = new ListNode(1, new ListNode(2));
  cyc.next!.next = cyc; // 1 -> 2 -> 1 ...
  console.log(hasCycle(cyc)); // true
}

main();
