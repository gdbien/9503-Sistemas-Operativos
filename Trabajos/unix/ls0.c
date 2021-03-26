#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

void ls0() {
    DIR* dir = opendir(".");
    if (!dir) perror("ls0");

    struct dirent *dirent;

    errno = 0;
    while ((dirent = readdir(dir))) {
        char * name= dirent->d_name;
        if (strcmp(name, ".") != 0 && strcmp(name, "..") != 0) printf("%s\n", name); 
    } 
    if (errno != 0) perror("ls0");

    if (closedir(dir) < 0) perror("ls0");
}

int main(void) {
    ls0();
}