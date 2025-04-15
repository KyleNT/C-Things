#include <stdio.h>
#include <string.h>

void string_char(void);
void string_coll(void);
int string_comp(void);

void main(void)
{
	string_char();
	string_coll();
	string_comp();
	
}

void string_char(void)
{
	char *p;
	
	p = strchr("1976 U.S. Election \n", '1');
	printf(p);
}

void string_coll(void)
{
	if(!strcoll("2008","2008")) printf("Igual \n");
	else printf("Diferente \n");
}

string_comp()
{
	char s[80];
	
	printf("Digite a senha: ");
	gets(s);
	
	if(strcmp(s, "2024")) {
		printf("Senha invalida \n");
		return 0;
	}
	return 1;
}
