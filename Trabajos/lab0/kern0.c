#include "c99int.h"
#define LONG_FILA 160 // 160 bytes = 80 char *2 (2 bytes per char)
#define MIN_FILA 0
#define MAX_FILA 24


static const volatile char * const VGABUF = (volatile char *) 0xb8000;

static void vga_write(const char *s, int8_t linea, uint8_t color) {
	volatile char* buf = (volatile char*) VGABUF;

	if (linea > MAX_FILA) return;
	if (linea < MIN_FILA) linea = (MAX_FILA+1) + linea;

	uint8_t line = linea; 

	buf = buf + line * LONG_FILA;

	while (*s != 0) {
        *buf++ = *s++;
        *buf++ = color;
    }	
 }

void main(void) {

    vga_write("OK",0,47);
    vga_write("HOLA",1,224);

    while (1) asm("hlt");  
}


