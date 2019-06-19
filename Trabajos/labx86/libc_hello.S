.globl main

main:
        push $msg
        call strlen
        push %eax
        push $msg
        push $1
        push $ret_pos
        jmp write
ret_pos:
        push $7
        call _exit

.data
msg:
        .ascii "Hello, world!\n"

