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
