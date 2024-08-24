AS := nasm 
ASFLAGS := -f elf32 

LD := x86_64-elf-ld
LDFLAGS := -melf_i386
LDFILE := link.ld

CC := x86_64-elf-gcc
CCFLAGS := -m32 -ffreestanding -fno-pie -c

SRC_C:= $(wildcard *.c)
SRC_NASM:= $(wildcard *.nasm)
OBJ:= $(patsubst %.c,%.o,$(SRC_C)) $(patsubst %.nasm,%.o,$(SRC_NASM)) 

MKRESCUE := grub-mkrescue # On your system it might be called differently

all: kernel

kernel: $(OBJ)
	$(LD) $(LDFLAGS) -T $(LDFILE)  $(OBJ)  -o $@ 


%.o: %.nasm
	$(AS) $(ASFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) $< -o $@

  
run: iso
	qemu-system-x86_64 -boot d -cdrom hello-world-kernel.iso -m 512


iso: kernel
	mkdir -p isodir/boot/grub
	cp kernel isodir/boot/
	cp grub.cfg isodir/boot/grub
	$(MKRESCUE) -o hello-world-kernel.iso isodir


clean:
	del *.o *.iso kernel 
