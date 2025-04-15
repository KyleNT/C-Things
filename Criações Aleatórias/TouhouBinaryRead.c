#include <stdio.h>
#include <stdlib.h>

struct Krause {
    int krause_1, krause_2;
    char kreis[50];
};

int main() {
    struct Krause klaus; //Declaração do Struct num
    FILE *fptr; //Declaração de um ponteiro para oa arquivo

	//Leitura de arquivo binário
    if ((fptr = fopen("krupp.bin", "rb")) == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

	int n;
    for (n = 0; n < 3; ++n) {
    	//Lê a estrutura num do arquivo e armazena na variável obj
        fread(&klaus, sizeof(struct Krause), 1, fptr);
        printf("Krause 1: %d\tKrause 2: %d\t Th Char: %s \n", klaus.krause_1, klaus.krause_2, klaus.kreis);
    }

    fclose(fptr);
    return 0;
} 

