#include "cpu.h" 

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

void cpu_reset(CPU *self, Mem *memory)
{
    self->PC = 0xFFFC;
    self->SP = 0x0100;
    self->D = 0;
    self->A = 0;
    self->Y = 0;
    self->X = 0;
    self->C = 0;
    self->Z = 0;
    self->I = 0; 
    self->B = 0;
    self->V = 0;
    self->N = 0;
    
    mem_init(memory);
}

Byte cpu_fetch(CPU *self, Mem *memory, u32 *cycles)
{
    Byte Data = mem_read_byte(memory, self->PC);
    self->PC++;
    cycles--;
    return Data;
}

void cpu_execute(CPU *self, Mem *memory, u32 cycles)
{
    while (cycles > 0)
    {
        Byte Instruction = cpu_fetch(self, memory, &cycles);
        switch(Instruction)
        {
            case INS_LDA_IM:
            {
               Byte value = cpu_fetch(self, memory, &cycles);
               self->A = value;
               self->Z = (self->A == 0);
               self->N = (self->A & 0b10000000) > 0;
            } break;
        }
    }
}
