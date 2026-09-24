// Run: npm run code -- 00-essentials.ts
export {};

// TypeScript / JavaScript essentials: arrays, map/set/strings,
// objects, array methods, functions/types, async/errors.

// --- Arrays: push/pop, numeric sort, copy, min/max/sum, swap, init ---
function essentialsArrays(): void {
  const nums: number[] = [3, 1, 2];
  nums.push(4);
  nums.pop();
  console.log("length:", nums.length);

  // Gotcha: default sort() is lexicographic — always pass a comparator for numbers.
  console.log("asc:", [...nums].sort((a, b) => a - b));
  console.log("desc:", [...nums].sort((a, b) => b - a));

  const copy = [...nums];
  console.log("copy:", copy);
  console.log("min:", Math.min(...nums), "max:", Math.max(...nums));
  console.log("sum:", nums.reduce((a, b) => a + b, 0));

  const arr = [1, 2, 3];
  [arr[0], arr[2]] = [arr[2], arr[0]];
  console.log("swapped:", arr);

  let lo = Infinity;
  let hi = -Infinity;
  for (const n of nums) {
    lo = Math.min(lo, n);
    hi = Math.max(hi, n);
  }
  console.log("lo:", lo, "hi:", hi);
}

// --- Map / Set / strings / ?? vs || / === / number limits ---
function essentialsMapSetString(): void {
  const nums = [1, 2, 2, 3, 3, 3];

  const freq = new Map<number, number>();
  for (const n of nums) {
    freq.set(n, (freq.get(n) ?? 0) + 1);
  }
  console.log("freq:", [...freq.entries()]);

  const seen = new Set<number>();
  seen.add(5);
  console.log("has 5:", seen.has(5));
  console.log("unique:", [...new Set(nums)]);

  const s = "Hello World";
  console.log("len:", s.length, "char:", s[1], "slice:", s.slice(0, 5));
  console.log("lower:", s.toLowerCase());
  console.log("sorted chars:", [..."cba"].sort().join(""));

  // ?? instead of || : 0 is a valid value, don't fall through on it.
  const m = new Map<string, number>([["a", 0]]);
  console.log("?? keeps 0:", m.get("a") ?? 99);

  console.log("strict eq:", (1 as unknown) === (1 as unknown));
  console.log("MAX_SAFE_INTEGER:", Number.MAX_SAFE_INTEGER);
}

// --- Objects: literals, destructuring, spread, optional chaining, helpers ---
function essentialsObjects(): void {
  const user = { id: 1, name: "Ada", role: "admin" as const, tags: ["a", "b"] };
  console.log("dot:", user.name, "bracket:", user["role"]);

  const { name, tags: [first] = [] } = user;
  console.log("destructured:", name, first);

  const updated = { ...user, name: "Grace", extra: true };
  console.log("spread override:", updated.name, updated.extra);

  const maybe: { profile?: { city?: string } } = {};
  console.log("optional chaining:", maybe.profile?.city ?? "unknown");

  console.log("keys:", Object.keys(user));
  console.log("values:", Object.values(user));
  console.log("entries:", Object.entries({ a: 1 }));

  const fromPairs = Object.fromEntries([
    ["x", 1],
    ["y", 2],
  ]);
  console.log("fromEntries:", fromPairs);
}

// --- Array methods: map/filter/reduce/find/some/every + slice/splice/sort/flat ---
function essentialsArrayMethods(): void {
  const nums = [5, 3, 8, 1, 2];

  console.log("map:", nums.map((n) => n * 2));
  console.log("filter:", nums.filter((n) => n % 2 === 0));
  console.log("reduce sum:", nums.reduce((a, b) => a + b, 0));
  console.log("find:", nums.find((n) => n > 4));
  console.log("findIndex:", nums.findIndex((n) => n > 4));
  console.log("some/every:", nums.some((n) => n > 7), nums.every((n) => n > 0));
  console.log("includes/indexOf:", nums.includes(3), nums.indexOf(8));

  console.log("slice (copy part):", nums.slice(1, 3), "original intact:", nums);
  const removed = [...nums];
  console.log("splice (mutates):", removed.splice(1, 2), "after:", removed);

  console.log("sort numbers:", [...nums].sort((a, b) => a - b));
  console.log("flat:", [1, [2, [3]]].flat(2));
  console.log("join:", ["a", "b"].join("-"));

  // Chaining: sum of squares of evens.
  console.log(
    "chain:",
    nums
      .filter((n) => n % 2 === 0)
      .map((n) => n * n)
      .reduce((a, b) => a + b, 0),
  );
}

// --- Functions + everyday types: params, generics, interfaces, unions, guards ---
function add(a: number, b = 0): number {
  return a + b;
}

const multiply = (a: number, b: number): number => a * b;

function sumAll(...ns: number[]): number {
  return ns.reduce((a, b) => a + b, 0);
}

function identity<T>(value: T): T {
  return value;
}

interface Point {
  x: number;
  y: number;
}

type Status = "ok" | "fail";

function describe(value: unknown): string {
  if (typeof value === "string") return `str:${value}`;
  if (typeof value === "number") return `num:${value}`;
  if (Array.isArray(value)) return `arr len ${value.length}`;
  return "other";
}

function essentialsFunctionsTypes(): void {
  console.log(add(2), add(2, 3), multiply(3, 4), sumAll(1, 2, 3, 4));
  console.log(identity<number>(7), identity("hi"));

  const p: Point = { x: 1, y: 2 };
  const s: Status = "ok";
  console.log(p, s);

  console.log(describe("a"), describe(5), describe([1, 2]), describe(null));
}

// --- Errors + async: try/catch with unknown, safe JSON, async/await, Promise.all ---
function safeParse(json: string): unknown {
  try {
    return JSON.parse(json);
  } catch (err) {
    console.log("parse failed:", err instanceof Error ? err.message : err);
    return null;
  }
}

const delay = (ms: number): Promise<string> =>
  new Promise((resolve) => setTimeout(() => resolve(`done in ${ms}ms`), ms));

async function essentialsAsyncErrors(): Promise<void> {
  console.log(safeParse('{"a":1}'));
  console.log(safeParse("oops"));

  console.log(await delay(10));
  console.log(await Promise.all([delay(10), delay(20)]));

  try {
    throw new Error("boom");
  } catch (err: unknown) {
    console.log("caught:", err instanceof Error ? err.message : "unknown");
  }
}

async function main(): Promise<void> {
  essentialsArrays();
  essentialsMapSetString();
  essentialsObjects();
  essentialsArrayMethods();
  essentialsFunctionsTypes();
  await essentialsAsyncErrors();
}

void main();
