#include <stdio.h>
int find_substr(char *s1, char *s2);
void main (void){
	if(find_substr("Chirumiru e BECC", "B") == -1)
		printf("Substring nao encontrada");
	else
		printf("Substring encontrada");
}

find_substr(char *s1, char *s2){
	register int t;
	char *p, *p2;
	
	for(t=0; s1[t]; t++){
		p = &s1[t];
		p2 = s2;
		
		while(*p2 && *p2==*p){
			p++;
			p2++;
		}
		if(!*p2) return t; //Primeiro Retorno
		
	}
	return -1; //Segundo Retorno
}
