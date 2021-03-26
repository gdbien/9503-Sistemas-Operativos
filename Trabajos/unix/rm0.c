#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>


void rm0(const char *file) {
   if(unlink(file) < 0) perror("rm0");
}

int main(int argc, char *argv[]) {
    rm0(argv[1]);
}