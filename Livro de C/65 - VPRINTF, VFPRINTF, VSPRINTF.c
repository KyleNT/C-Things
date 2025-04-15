#include <stdio.h>
#include <stdarg.h>

void print_message(char *format, ...);

void main(void)
{
	print_message("O arquivo nao pode ser aberto %s.", "teste");
}

void print_message(char *format, ...)
{
	va_list ptr;
	
	va_start(ptr, format);
	
	vprintf(format, ptr);
	
	va_end(ptr);
}
