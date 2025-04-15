#include <stdio.h>
#include <string.h>

void caixa_alta(char ch);
void caixa_baixa(char ch);

void main(void){
	char ch = 'a';
	
	caixa_alta(ch);
	caixa_baixa(ch);
}

void caixa_alta(char ch)
{
	putchar(toupper(ch));
	printf("\n");
}

void caixa_baixa(char ch)
{
	putchar(tolower(ch));
	printf("\n");	
}
