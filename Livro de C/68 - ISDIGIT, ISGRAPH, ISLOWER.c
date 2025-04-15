#include <ctype.h>
#include <stdio.h>

void digito(void);
void impresso(void);
void minusculo(void);

void main(void)
{
	digito();
	impresso();
	minusculo();
}

void digito(void)
{
	char ch;
	for(;;){
		ch = getchar();
		if(ch==' ') break;
		if(isdigit(ch)) printf("%c e um digito \n", ch);
	}
}

void impresso(void)
{
	char ch;
	
	for(;;) {
		ch = getchar();
		if(ch==' ') break;
		if(isgraph(ch)) printf("%c pode ser impresso \n", ch);
	}
}

void minusculo(void)
{
	char ch;
	for(;;)
	{
		ch=getchar();
		if(ch==' ') break;
		if(islower(ch)) printf("%c e minusculo \n", ch);
	}
}
