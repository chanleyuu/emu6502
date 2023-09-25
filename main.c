#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"

int main() 
{
    Mem ram;
    CPU cpu;
    cpu_reset(&cpu, &ram);
    cpu.cycles = 2;
    //inline program
    ram.Data[0xFFFC] = INS_LDA_IM;
    ram.Data[0xFFFD] = 0x42;
    //end lnline program
    cpu_execute(&cpu, &ram);
    return 0;
}    
