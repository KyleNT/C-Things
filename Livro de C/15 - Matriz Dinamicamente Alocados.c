#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main(void){
	char *s;
	register int t;
	
	s = malloc(80);
	
	if(!s){
		printf("Erro na soliticacao de memoria. \n");
		exit(1);
	}
	
	gets(s);
	for(t=strlen(s)-1; t>=0;t--) putchar(s[t]);
}
