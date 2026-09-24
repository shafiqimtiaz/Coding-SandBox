// `npm run code` → pick a file. `npm run code -- <file> [args]` → run it directly.
import { readdir } from "node:fs/promises";
import { spawn } from "node:child_process";
import { select } from "@inquirer/prompts";

function run(tsxArgs) {
  const child = spawn("npx", ["tsx", ...tsxArgs], { stdio: "inherit" });
  child.on("exit", (code) => process.exit(code ?? 0));
}

const args = process.argv.slice(2);
if (args.length > 0) {
  run(args);
} else {
  const files = (await readdir(new URL(".", import.meta.url)))
    .filter((f) => f.endsWith(".ts"))
    .sort();
  const file = await select({
    message: "Pick a file to run:",
    choices: files.map((f) => ({ value: f })),
  });
  run([file]);
}
