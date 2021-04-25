#ifndef __TRAPFRAME_H_
#define __TRAPFRAME_H_

// RISC-V Trapframe


typedef struct
{
  long gpr[32];
  long status;
  long epc;
  long badvaddr;
  long cause;
  long insn;
} trapframe_t;

#endif