#include <ctype.h>
#include <stdio.h>

void alfanumerico(void);
void letra(void);
void controle(void);

void main(void)
{
	alfanumerico();
	letra();
	controle();
}

void alfanumerico(void)
{
	char ch;
	for(;;){
		ch = getc(stdin);
		if(ch==' ') break;
		if(isalnum(ch)) printf("%c e alfanumerico \n", ch);
	}
}

void letra(void)
{
	char ch;
	
	for(;;) {
		ch = getchar();
		if(ch==' ') break;
		if(isalpha(ch)) printf("%c e uma letra \n", ch);
	}
}

void controle(void)
{
	char ch;
	for(;;)
	{
		ch=getchar();
		if(ch==' ') break;
		if(iscntrl(ch)) printf("%c e um caractere de controle \n", ch);
	}
}
