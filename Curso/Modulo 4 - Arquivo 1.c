#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	srand(time(NULL)); //Usa o tempo atual como semente
	//Números aleatórios de 7 a 16
	int max = 16;
	int min = 7;
	//int r = rand() % 10; //Gera um número random de 0 a 9
	//int r = (rand() % 10) + 7; //Numero random de 7 a 16.
	int r = (rand() % (max - min + 1) + min; //Traduzindo: 16 - 7 + 1= 10, ou seja teremos um número entre 0 a 9 + 7, ou seja, min 7 e max 16
	printf("Numero gerado: %d", r); //Imprime um numero gerado
	
	return 0;
}
