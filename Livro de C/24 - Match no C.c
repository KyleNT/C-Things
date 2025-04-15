#include <stdio.h>
char *match(char c, char *s);

void main(void){
	char s[80], *p, ch;
	gets(s);
	ch = getchar();
	p = match(ch, s);
	
	if(*p)
	{
		printf("%s ", p);
	} else {
		printf("%c nao encontrado", ch);
	}
}

char *match(char c, char *s){
	while(c!=*s && *s) s++;
	return(s);
}
