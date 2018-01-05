TOOL=/opt/i686-pc-elf/bin
AR=$(TOOL)/i686-pc-elf-ar
AS=$(TOOL)/i686-pc-elf-as
CC=$(TOOL)/i686-pc-elf-gcc
CXX=$(TOOL)/i686-pc-elf-g++
LD=$(TOOL)/i686-pc-elf-ld

SRC=$(wildcard *.c)
NAS=$(wildcard *.asm)
GAS=$(wildcard *.s)
OBJ=$(patsubst %.c, %.o, $(SRC)) $(patsubst %.asm, %.o, $(NAS)) $(patsubst %.s, %.o, $(GAS))
HDR=$(wildcard *.h)

libostool.a: $(OBJ)
	$(AR) r $@ $^

%.o: %.c $(HDR)
	$(CC) -c -o $@ $<

%.o: %.asm
	nasm -f elf -o $@ $<

%.o: %.s
	$(AS) -o $@ $<

clean:
	-rm -f $(OBJ) libostool.a
