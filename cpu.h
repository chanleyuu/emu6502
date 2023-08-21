#define MAX_MEM (1024 * 64)

//opcodes
#define INS_LDA_IM 0xA9 //Load Accumulator

typedef unsigned char Byte;
typedef unsigned short Word; 

typedef unsigned int u32;

typedef struct Mem
{
    //const u32 MAX_MEM = 65536;
    Byte Data[MAX_MEM];
} Mem;

void mem_init(Mem *self)
{
    for (u32 i = 0; i < MAX_MEM; i++) {
        self->Data[i] = 0;
    }
}

//read 1 byte
Byte mem_read_byte(Mem *ram, u32 addr)
{
    //assert here that addr is less than MAX_MEM
    if (addr < MAX_MEM){
        return ram->Data[addr];
    }
}

typedef struct CPU
{
    
    Word PC;    //Program counter
    Word SP;    //Stack pointer
    
    Byte A, X, Y; //Registers

    Byte C : 1; //status flags
    Byte Z : 1;
    Byte I : 1;
    Byte D : 1;
    Byte B : 1;
    Byte V : 1;
    Byte N : 1;
    
    
} CPU;

void cpu_reset(CPU *self, Mem *memory);


Byte cpu_fetch(CPU *self, Mem *memory, u32 *cycles);


void cpu_execute(CPU *self, Mem *memory, u32 cycles);

