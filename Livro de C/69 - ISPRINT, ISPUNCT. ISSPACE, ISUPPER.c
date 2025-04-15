#include <ctype.h>
#include <stdio.h>

void e_print(void);
void e_punt(void);
void e_space(void);
void e_upper(void);

void main(void)
{
	e_print();
	e_punt();
	e_space();
	e_upper();
}

void e_print(void)
{
	char ch;
	for(;;){
		ch = getchar();
		if(isprint(ch)) printf("%c pode ser impresso \n", ch);
		if(ch==' ') break;
	}
}

void e_punt(void)
{
	char ch;
	
	for(;;) {
		ch = getchar();
		if(ch==' ') break;
		if(ispunct(ch)) printf("%c e pontuacao \n", ch);
	}
}

void e_space(void)
{
	char ch;
	for(;;)
	{
		ch=getchar();
		if(isspace(ch)) printf("'%c' e um espaco em branco \n", ch);
		if(ch==' ') break;
	}
}

void e_upper(void)
{
	char ch;
	for(;;)
	{
		ch=getchar();
		if(ch==' ') break;
		if(isupper(ch)) printf("%c e maiusculo \n", ch);
	}
}
