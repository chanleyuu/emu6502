 
C=gcc
OUTPUT_OPTIONS=-MMD -MP -o  $@

#LIBS= -lglfw -lvulkan -lm
 
TARGET = emu6502 
 

COMPILE.c = $(C) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c 

 

SRC=$(main *.c)

OBJ=$(patsubst %.c, %.o, $(srcfiles))

DEP=$(SRC:.c=.d)

 

#.PHONY: clean

#all: $(TARGET)

emu6502: main.o cpu.o # This line will compile to .o every .c which need to be (which have been modified)
	$(C) -o emu6502 main.o cpu.o

main.o: main.c
	$(C) -c main.c
	
cpu.o: cpu.c
	$(C) -c cpu.c cpu.h
#$(OBJ): $(SRC)
#	$(CXX) $(OUTPUT_OPTIONS) $(LDLIBS) $(SRC)

	
-include $(DEP)


clean:

	rm -f $(OBJ) $(DEP) main.o emu6502
