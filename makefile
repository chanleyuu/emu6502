 
C=gcc
OUTPUT_OPTIONS=-MMD -MP -o  $@

#LIBS= -lglfw -lvulkan -lm
 
TARGET = emu6502 
 

COMPILE.c = $(C) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c 

 

SRC=$(main *.c, *.c, *.h)

OBJ=$(patsubst %.c, %.o, $(srcfiles))

DEP=$(SRC:.c=.d)

 

#.PHONY: clean

#all: $(TARGET)

emu6502: main.o cpu.o # This line will compile to .o every .c which need to be (which have been modified)
	$(C) $(DEBUG) -o emu6502 main.o cpu.o

debug:  DEBUG = -g

debug: emu6502

	
main.o: main.c
	$(C) $(DEBUG) -c main.c cpu.h
	
cpu.o: cpu.c
	$(C) $(DEBUG) -c  cpu.h cpu.c
#$(OBJ): $(SRC)
#	$(CXX) $(OUTPUT_OPTIONS) $(LDLIBS) $(SRC)

-include $(DEP)


clean:

	rm -f $(OBJ) $(DEP) main.o cpu.o emu6502
