# stackmaster-vm

A tiny stack-based virtual machine written in C, built to explore the core ideas behind computer organization: program counters, stack pointers, and the fetch-decode-execute cycle.

## What it does

The VM lets you interactively build a small "program" made up of instructions (`PUSH`, `POP`, `ADD`), then executes them one at a time against an internal stack — similar in spirit to how a real CPU or a bytecode interpreter (like the JVM) operates.

On startup, it repeatedly prompts:

```
which operation would you like to do? 1 for PUSH, 2 for POP, 3 for ADD, else exit
```

Entering `1` (PUSH) also prompts for a value to push. Entering anything other than `1`, `2`, or `3` ends input and runs the program you built. Up to 10 instructions can be entered.

### Example session

Entering `PUSH 9`, `PUSH 2`, `POP`, `PUSH 1`, `ADD`, then exiting produces this trace:

| Step     | Stack   |
|----------|---------|
| PUSH 9   | [9]     |
| PUSH 2   | [9, 2]  |
| POP      | [9]     |
| PUSH 1   | [9, 1]  |
| ADD      | [10]    |

Final output: `10`

## How it works

- **`struct Instruction`** — holds an opcode (`enum OpCode`) and an operand value.
- **`struct VM`** — holds the instruction array, a program counter (`pc`), a value stack, and a stack pointer (`sp`).
- **`push` / `pop`** — manipulate the VM's internal stack.
- **`run`** — the fetch-decode-execute loop: reads the instruction at `pc`, branches on its opcode via a `switch`, executes it, then advances `pc`.
- **`main`** — interactively collects up to 10 instructions from the user (with bounds-checking so input stops once the instruction array is full), then calls `run`.

## Build & run

```
gcc stack.c -o stack
./stack
```

Follow the prompts to build your program, then see the final top-of-stack value printed at the end.

## Possible next steps

- Additional opcodes (`SUB`, `MUL`, `JMP`, `PRINT`)
- A simple text-based assembler so programs can be written as strings instead of typed in interactively
- Bounds-checking on the value stack itself (currently only the instruction array is guarded)
- Step-by-step execution tracing/printing
