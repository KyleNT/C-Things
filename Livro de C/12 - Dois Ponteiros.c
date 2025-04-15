#include <stdio.h>
#include <string.h>

char *s = "Whatifalthist isn\'t a Chirumiru, because he\'s British and he\'s called Rudyard, a non-Chirumiru name";


void main(void){
	
	//Dois Ponteiros
	int x, *p, **q;
	register int t;
	
	x = 10;
	p = &x;
	q = &p;
	
	printf("%d \n", **q);
	
	//Inicialização de Ponteiros
	printf("%s \n", s);
	for(t=strlen(s)-1; t>-1; t--) printf("%c", s[t]);
	
}
