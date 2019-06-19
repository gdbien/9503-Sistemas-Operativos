CFLAGS := -g -m32 -O1 -fno-inline
SRCS := $(wildcard *.c)  # usar wildcard *.c
OBJS := $(patsubst %.c,%.o,$(SRCS))  # usar patsubst sobre SRCS

QEMU := qemu-system-i386 -serial mon:stdio
KERN := kern0
BOOT := -kernel $(KERN)

qemu: $(KERN)
	$(QEMU) $(BOOT)

qemu-gdb: $(KERN)
	$(QEMU) -kernel kern0 -S -gdb tcp:127.0.0.1:7508 $(BOOT)

gdb:
	gdb -q -s kern0 -n -ex 'target remote 127.0.0.1:7508'

kern0: boot.o $(OBJS)
	ld -m elf_i386 -Ttext 0x100000 --entry main $^ -o $@
	objdump -S kern0 >kern0.asm
	# Verificar imagen Multiboot v1.
	grub-file --is-x86-multiboot $@

%.o: %.S
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f kern0 *.o *.asm core

.PHONY: clean qemu qemu-gdb gdb