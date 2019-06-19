
kern0:     file format elf32-i386


Disassembly of section .text:

00100000 <multiboot>:
  100000:	02 b0 ad 1b 00 00    	add    0x1bad(%eax),%dh
  100006:	00 00                	add    %al,(%eax)
  100008:	fe 4f 52             	decb   0x52(%edi)
  10000b:	e4                   	.byte 0xe4

0010000c <vga_write>:
static const volatile char * const VGABUF = (volatile char *) 0xb8000;

static void vga_write(const char *s, int8_t linea, uint8_t color) {
	volatile char* buf = (volatile char*) VGABUF;

	if (linea > MAX_FILA) return;
  10000c:	80 fa 18             	cmp    $0x18,%dl
  10000f:	7f 36                	jg     100047 <vga_write+0x3b>
#define MAX_FILA 24


static const volatile char * const VGABUF = (volatile char *) 0xb8000;

static void vga_write(const char *s, int8_t linea, uint8_t color) {
  100011:	56                   	push   %esi
  100012:	53                   	push   %ebx
  100013:	89 d3                	mov    %edx,%ebx
	volatile char* buf = (volatile char*) VGABUF;

	if (linea > MAX_FILA) return;
	if (linea < MIN_FILA) linea = (MAX_FILA+1) + linea;
  100015:	8d 72 19             	lea    0x19(%edx),%esi
  100018:	84 d2                	test   %dl,%dl
  10001a:	0f 48 de             	cmovs  %esi,%ebx

	uint8_t line = linea; 

	buf = buf + line * LONG_FILA;
  10001d:	0f b6 d3             	movzbl %bl,%edx
  100020:	69 d2 a0 00 00 00    	imul   $0xa0,%edx,%edx
  100026:	81 c2 00 80 0b 00    	add    $0xb8000,%edx

	while (*s != 0) {
  10002c:	0f b6 18             	movzbl (%eax),%ebx
  10002f:	84 db                	test   %bl,%bl
  100031:	74 12                	je     100045 <vga_write+0x39>
        *buf++ = *s++;
  100033:	83 c0 01             	add    $0x1,%eax
  100036:	88 1a                	mov    %bl,(%edx)
        *buf++ = color;
  100038:	88 4a 01             	mov    %cl,0x1(%edx)

	uint8_t line = linea; 

	buf = buf + line * LONG_FILA;

	while (*s != 0) {
  10003b:	0f b6 18             	movzbl (%eax),%ebx
        *buf++ = *s++;
        *buf++ = color;
  10003e:	8d 52 02             	lea    0x2(%edx),%edx

	uint8_t line = linea; 

	buf = buf + line * LONG_FILA;

	while (*s != 0) {
  100041:	84 db                	test   %bl,%bl
  100043:	75 ee                	jne    100033 <vga_write+0x27>
        *buf++ = *s++;
        *buf++ = color;
    }	
 }
  100045:	5b                   	pop    %ebx
  100046:	5e                   	pop    %esi
  100047:	c3                   	ret    

00100048 <main>:

void main(void) {

    vga_write("OK",0,47);
  100048:	b9 2f 00 00 00       	mov    $0x2f,%ecx
  10004d:	ba 00 00 00 00       	mov    $0x0,%edx
  100052:	b8 73 00 10 00       	mov    $0x100073,%eax
  100057:	e8 b0 ff ff ff       	call   10000c <vga_write>
    vga_write("HOLA",1,224);
  10005c:	b9 e0 00 00 00       	mov    $0xe0,%ecx
  100061:	ba 01 00 00 00       	mov    $0x1,%edx
  100066:	b8 76 00 10 00       	mov    $0x100076,%eax
  10006b:	e8 9c ff ff ff       	call   10000c <vga_write>

    while (1) asm("hlt");  
  100070:	f4                   	hlt    
  100071:	eb fd                	jmp    100070 <main+0x28>
