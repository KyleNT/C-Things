#include <stdio.h>
#include <conio.h>

void main(void)
{
	char str[80];
	_cprintf("Eu assisto Canal 1\n");
	_cputs("Eu assisto Canal 2 \n");
	_cprintf("Que canal voce assiste? \n");
	_cscanf("%s", str);
	_getch();
	_cprintf("Voce assiste: %s", str);
}
