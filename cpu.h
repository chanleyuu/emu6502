#define MAX_MEM (1024 * 64)

//opcodes
#define INS_LDA_IM 0xA9 //Load Accumulator immediate
#define INS_LDA_ZP 0xA5 //Load Accumulator zero page

#include <stdio.h>

typedef unsigned char Byte;
typedef unsigned short Word; 

typedef unsigned int u32;

typedef struct Mem
{
    //const u32 MAX_MEM = 65536;
    Byte Data[MAX_MEM];
} Mem;


typedef struct CPU
{
    u32 cycles;
    
    Word PC;    //Program counter
    Word SP;    //Stack pointer
    
    Byte A, X, Y; //Registers

    //status flags
    Byte C : 1; //Carry
    Byte Z : 1; //Zero
    Byte I : 1; //Interrupt Disable
    Byte D : 1; //Decimal
    Byte B : 1; //Break flag
    Byte V : 1; //Overflow
    Byte N : 1; //Negative
    
    
} CPU;

void mem_init(Mem *self);

//read 1 byte
Byte mem_read_byte(Mem *ram, u32 addr);

void cpu_reset(CPU *self, Mem *memory);

Byte cpu_fetch(CPU *self, Mem *memory);

void cpu_load_setstatus()

Byte cpu_read(CPU *self, Mem *memory, Byte address);

void cpu_execute(CPU *self, Mem *memory);

