#include <stdio.h>
#include<conio.h>
#include <string.h>

int main(){
	
	char *text[1];
	text[0] = "Oku";
	char *decl[12];
	decl[0] = "us";
	decl[1] = "us";
	decl[2] = "ui";
	decl[3] = "um";
	decl[4] = "u";
	decl[5] = "us";
	
	decl[6] = "us";
	decl[7] = "uum";
	decl[8] = "ibus";
	decl[9] = "us";
	decl[10] = "ibus";
	decl[11] = "us";
	
	char *nom[12];
	nom[0] = "Nominative, Singular: \t";
	nom[1] = "Genitive, Singular: \t";
	nom[2] = "Dative, Singular: \t";
	nom[3] = "Accusative, Singular: \t";
	nom[4] = "Ablative, Singular: \t";
	nom[5] = "Vocative, Singular: \t";
	
	nom[6] = "Nominative, Plural: \t";
	nom[7] = "Genitive, Plural: \t";
	nom[8] = "Dative, Plural: \t";
	nom[9] = "Accusative, Plural: \t";
	nom[10] = "Ablative, Plural: \t";
	nom[11] = "Vocative, Plural: \t";
	
	printf("\n ---------- \n");
	printf("Latinizador, Radical: \t %s- \n", text[0]);
	printf("\n ---------- \n");
	
	int counta = 0;
	while(counta < 12){
		
		int containter = 0;
		if (counta == 6){
			printf("\n");	
		}
		printf("%s", nom[counta]);	
		printf("%s", text[0]);
		printf("%s \n", decl[counta]);
		counta++;
	}
	
	return 0;
}
