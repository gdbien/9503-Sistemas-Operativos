CFLAGS := -m32 -g -std=c99 -Wall -Wextra -Wpedantic
CFLAGS += -O1 -fno-pic -fno-omit-frame-pointer -no-pie
ASFLAGS = $(CFLAGS)

ASMS := $(wildcard *.S)  # wildcard *.S
SRCS := $(wildcard *.c)  # usar wildcard *.c

PROG := $(patsubst %.S,%,$(ASMS))
PROG += $(patsubst %.c,%,$(SRCS))

hello: hello.c lib/exit.c

sys_%: sys_%.S
	$(CC) $(ASFLAGS) $(CPPFLAGS) -nostartfiles $< -o $@

all: $(PROG)

clean:
	rm -f $(PROG) *.o core

.PHONY: clean all