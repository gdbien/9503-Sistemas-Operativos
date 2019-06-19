#include <sys/syscall.h>  // SYS_write, SYS_exit

.globl main
main:
		push $msg
        call puts     
        pop %eax
        ret

.data
msg:
        .ascii "Hello, world!"
