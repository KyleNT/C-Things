#include <ctype.h>
#include <stdio.h>

void digitoX(void);

void main(void)
{
	digitoX();	
}

void digitoX(void)
{
	char ch;
	for(;;){
		ch = getchar();
		if(isxdigit(ch)) printf("%c e hexadecimal \n", ch);
		if(ch==' ') break;
	}
}
