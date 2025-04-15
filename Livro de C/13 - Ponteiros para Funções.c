#include <stdio.h>
#include <string.h>

void check(char *a, char *b, int (*cmp) (const char *, const char *));
void checked(int (*cmp)());
const char* boanoite();

void main (void){
	char s1[100],s2[100];
	int (*p)();
	int (*w)();
	
	p = strcmp;
	w = boanoite;
	
	printf("Digite a primeira declaracao: \t");
	gets(s1);
	printf("Digite a segunda declaracao: \t");
	gets(s2);
	
	check(s1, s2, p);
	
	printf("\nChecagem de Cumprimento: ");
	checked(w);
	
}

void check(char *a, char *b, int (*cmp) (const char *, const char *)){
	printf("Testando igualdade\n");
	if (!(*cmp)(a,b)) printf("Igual\n");
	else printf("Diferente\n");
}


const char* boanoite(){
	return "Boa noite!";
}

void checked(int (*cmp)()){
	printf("%s", (*cmp)());
}
