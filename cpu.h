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

void mem_init(Mem *self);

//read 1 byte
Byte mem_read_byte(Mem *ram, u32 addr);

void cpu_reset(CPU *self, Mem *memory);


Byte cpu_fetch(CPU *self, Mem *memory, u32 *cycles);


void cpu_execute(CPU *self, Mem *memory, u32 cycles);

