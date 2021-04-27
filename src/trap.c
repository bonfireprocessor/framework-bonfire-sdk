#include "bonfire.h"
#include "console.h"
#include "uart.h"

__attribute__((weak)) trapframe_t* riscv_trap_handler(trapframe_t *ptf);

trapframe_t* riscv_trap_handler(trapframe_t *ptf)
{
 
    printk("\nTrap cause: %lx\n",ptf->cause);
    dump_tf(ptf);
    char c=uart_readchar();
    if (c=='r' || c=='R')
        ptf->epc=SRAM_BASE; // will cause reset
    else
        if (((long)ptf->cause)>0) ptf->epc+=4;   
    return ptf;
}