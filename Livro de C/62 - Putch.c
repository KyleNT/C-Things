#include <stdio.h>
#include <conio.h>

void main (void)
{
	char str[] = "Guerra de Ucr�nia, em 2022";
	char *ptr = str;
	for (; *ptr; ptr++) putch(*ptr);
}
