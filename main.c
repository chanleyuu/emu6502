#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"

int main() 
{
    Mem ram;
    CPU cpu;
    cpu_reset(&cpu, &ram);
    cpu_execute(&cpu, &ram, 2);
    return 0;
}    
