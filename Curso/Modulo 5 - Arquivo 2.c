#include <stdio.h>
#define TAM 3
#define TAM_2 2
int main(){
	
	/* ARQUIVO 2 - 1: VETORES */
	/*
	int vetor[TAM] = {0,1,2};
	//int vet[] = {1,2,3,4};
	char vetoral[TAM] = {'a','b','c'};
	
	// Vetor[3] => índices0,1,2 
	//Vetor tem que ser menor que o vetor, e inteiro
	//vetor[0] = 10
	//scanf("%d", &vetor[0]);
	//printf("%d", vetor[0]);
	
	int i = 0;
	for(i = 0; i < TAM; i++){
		printf("%c \n", vetoral[i]);
	}
	for(i = 0; i < TAM; i++){
		printf("%d \n", vetor[i]);
	}
	*/
	
	/* ARQUIVO 2 - 2: STRINGS */
	//Para armazenar stings, no final, tem que ter um \0
	/*
	char ching[] = "Ching Chong";
	char ching0[] = "";
	char ching1[255] = "";
	char ching_dois[6] = {'c','h','i','n','g','\0'};
	
	fflush(stdin);
	printf("%s \n", ching); //Imprime String sem espaço
	puts(ching); //Imprime String com espaço
	
	fflush(stdin);
	scanf("%s", ching0); //Lê Strings sem espaço
	fflush(stdin);
	fgets(ching1, sizeof(ching1), stdin); //Lê Strings com espaço, tem 3 parâmetros, String, Tamanho máximo, por onde será feita a leitura
	
	printf("%s \n", ching0);
	puts(ching1);
	*/
	
	/* Arquivo 2 - 3: Matrizes*/
	//São vetores multidimensionais
	int vetor[2][3] = {{1,2,3},{4,5,6}};
	char vetoral[TAM_2][TAM_2] = {{'a','b'},{'c','d'}};
	//X e Y devem ser inteiros menores que o tamanho da matriz em -1
	
	int i,j;
	for(i = 0; i < TAM_2; i++){
		for(j = 0; j < TAM_2; j++){
			scanf("%c", &vetoral[i][j]);
			fflush(stdin);
		}
		printf("\n");	
	}
	for(i = 0; i < TAM_2; i++){
		for(j = 0; j < TAM_2; j++){
			printf("%c ", vetoral[i][j]);
		}
		printf("\n");	
	}
	return 0;
}
