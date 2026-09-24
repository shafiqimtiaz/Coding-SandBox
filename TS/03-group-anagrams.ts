// Run: npm run code -- 03-group-anagrams.ts
export {};

// Pattern: HashMap keyed by sorted signature. Time O(n * k log k), space O(n * k).

function groupAnagrams(strs: string[]): string[][] {
  const groups = new Map<string, string[]>();
  for (const s of strs) {
    const key = [...s].sort().join("");
    if (!groups.has(key)) {
      groups.set(key, []);
    }
    groups.get(key)!.push(s);
  }
  return [...groups.values()];
}

function main(): void {
  console.log(groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]));
  console.log(groupAnagrams([""])); // [[""]]
}

main();
