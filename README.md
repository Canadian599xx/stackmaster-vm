# stackmaster-vm

A tiny stack-based virtual machine written in C, built to explore the core ideas behind computer organization: program counters, stack pointers, and the fetch-decode-execute cycle.

## What it does

The VM reads a small hardcoded "program" made up of instructions (`PUSH`, `POP`, `ADD`) and executes them one at a time against an internal stack, similar in spirit to how a real CPU or a bytecode interpreter (like the JVM) operates.

Example program encoded in `main`:

```
PUSH 9
PUSH 2
POP
PUSH 1
ADD
```

Trace through execution:

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

## Build & run

```
gcc stack.c -o stack
./stack
```

Expected output: `10`

## Possible next steps

- Additional opcodes (`SUB`, `MUL`, `JMP`, `PRINT`)
- A simple text-based assembler so programs can be written as strings instead of hardcoded structs
- Bounds-checking on the stack and instruction array
- Step-by-step execution tracing/printing
