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

//read 1 byte
void mem_write_byte(Mem *ram, u32 addr, Byte value)
{
    //assert here that addr is less than MAX_MEM
    if (addr < MAX_MEM){
        ram->Data[addr] = value;
    }
}

void cpu_reset(CPU *self, Mem *memory)
{
    self->cycles = 0;
    
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

//Fetch one byte from memory
Byte cpu_fetch(CPU *self, Mem *memory)
{
    Byte Data = mem_read_byte(memory, self->PC);
    self->PC++;
    self->cycles--;
    int c = self->cycles;
    return Data;
}

//Read one byte in memory as a cycle but does not move the program counter
Byte cpu_read(CPU *self, Mem *memory, Byte address)
{
    Byte Data = mem_read_byte(memory, address);
    self->cycles--;
    int c = self->cycles;
    return Data;
}

void cpu_load_setstatus(CPU *self)
{
    self->Z = (self->A == 0); //Set Z flag if Accumulator is zero
    self->N = (self->A & 0b10000000) > 0; //A is negative if negative flag is set
}

void cpu_execute(CPU *self, Mem *memory)
{
    self->cycles;
    
    while (self->cycles > 0)
    {
        Byte Instruction = cpu_fetch(self, memory);
        switch(Instruction)
        {
            case INS_LDA_IM:
            {
               Byte value = cpu_fetch(self, memory);
               self->A = value;
               cpu_load_setstatus(self);
            } break;
            case INS_LSA_ZP:
            {
                Byte ZeroPageAddress = cpu_fetch(self, memory);
                A = ReadByte(self, memory, ZeroPageAddress);
                cpu_load_setstatus(self);
            } break;
            default:
            {
                printf("Could not execute instruction %d !!!!", Instruction);
            } break;
        }
    }
}
