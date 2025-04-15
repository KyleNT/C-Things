#include <stdio.h>

int main(){
	
	FILE *file = fopen("Jogue_a_mao_na_cabeca.txt", "w"); // Aberto para escrita
	fprintf(file, "E depois, %s!\n", "para o ar");

	return 0;
}
