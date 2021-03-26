#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char buffer[8192];

void cat0(const char *file) {
	int f;
	ssize_t bytesLeidos;
	ssize_t bytesEscritos;

	if ((f = open(file, O_RDONLY)) < 0) {
		perror("cat0: Error al abrir el archivo");
		return;
	}

	while ((bytesLeidos = read(f, buffer, sizeof(buffer))) > 0) {
		if ((bytesEscritos = write(STDOUT_FILENO, buffer, bytesLeidos)) != bytesLeidos) {
			perror("cat0: Error al copiar");
			break;
		}
	}
	if (bytesLeidos < 0) perror("cat0: Error al leer");
	if (close(f) < 0) perror("cat0: Error al cerrar el archivo");
}

int main(int argc, char *argv[]) {
    cat0(argv[1]);
}