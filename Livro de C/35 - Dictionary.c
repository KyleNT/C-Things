#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

char *aurelioc[][100] = {
	"Alemanha", "Berlim",
	"Albania", "Tirana",
	"Africa do Sul", "Pretoria",
	"Brasil", "Brasilia",
	"China", "Pequim",
	"Coreia do Sul", "Seul",
	"EUA", "Washington D.C.",
	"Hungria", "Budapeste",
	"Japao", "Toquio",
	"Polonia", "Varsovia",
	"Russia", "Moscou",
	"Taiwan", "Taipe",
	"Zimbabue", "Harare",
	"", ""
};

void main(void){
	char word[100], ch;
	char **p;
	
	do {
		puts("\nEntre a palavra: ");
		gets(word);
		
		p = (char **)aurelioc;
		do{

			if(!strcmp(*p, word)){
				puts("Significado: ");
				puts(*(p+1));
			}
			if(!strcmp(*p, word)) break;
			p = p + 2;
		} while(*p);
		
		if(!*p) puts("A palavra nao esta no dicionario");
		printf("Outra? (y/n): ");
		ch = getche();
	} while(toupper(ch) != 'N');
}
