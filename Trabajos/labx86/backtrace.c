#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
 // Formato #numfrm [FP] ADDR ( ARG1 ARG2 ARG3 )
void backtrace() {
	uintptr_t* ebp = __builtin_frame_address(0);
	unsigned int numfrm = 1;

    ebp = *ebp;

	while (ebp != 0) {
		printf("#%u [%p] %p ( %p %p %p )\n",
			   numfrm,ebp,*(ebp+1),
			   *(ebp+2),*(ebp+3),*(ebp+4));

		ebp = *ebp;
		numfrm++;
	}
}

void my_write(int fd, const void *msg, size_t count) {
    backtrace();
    fprintf(stderr, "=> write(%d, %p, %zu)\n", fd, msg, count);
    write(fd, msg, count);
}

void recurse(int level) {
    if (level > 0)
        recurse(level - 1);
    else
        my_write(2, "Hello, world!\n", 15);
}

void start_call_tree() {
    recurse(5);
}

int main(void) {
    start_call_tree();
}