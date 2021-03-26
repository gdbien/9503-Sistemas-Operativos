#define _BSD_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void stat0(const char *file) {
	struct stat statbuf;
	if (stat(file, &statbuf) < 0) {
		perror("stat0");
		return;
	}

	printf("Size: %ld\n",statbuf.st_size);
	printf("File: %s\n",file);
	printf("Type: ");
	switch (statbuf.st_mode & S_IFMT) {
        case S_IFBLK:  printf("block device\n");     break;
        case S_IFCHR:  printf("character device\n"); break;
        case S_IFDIR:  printf("directory\n");        break;
        case S_IFIFO:  printf("FIFO/pipe\n");        break;
        case S_IFLNK:  printf("symlink\n");          break;
        case S_IFREG:  printf("regular file\n");     break;
        case S_IFSOCK: printf("socket\n");           break;
        default:       printf("unknown?\n");         break;
    }
}

int main(int argc, char *argv[]) {
    stat0(argv[1]);
}