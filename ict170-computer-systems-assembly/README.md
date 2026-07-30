# Foundations of Computer Systems — x86 Assembly

A set of small x86 assembly (MASM/TASM, 16-bit real mode) programs written while learning how computers work at the machine/instruction level: registers, memory, conditional jumps, loops, and string handling.

## What's included

- `IFELSE.asm`, `ANDPGMLASM.asm` — conditional logic (compare, jump-if-above, AND operations)
- `LOOPGMLASM.asm`, `WHILEX.asm` — loop constructs
- `STREX.asm` — string handling
- `simpledivision.asm`, `twodig.asm` — arithmetic (division, two-digit number handling)
- `program.asm`, `program1.asm`, `program2.asm`, `SIMF.asm`, `simpf.asm` — general practice programs

Each program directly manipulates registers and memory and prints output via DOS interrupts (`INT 21H`) — this is close to how a CPU actually executes instructions, one level above raw binary/machine code.

Built as part of a Murdoch University unit, ICT170 Foundations of Computer Systems.
