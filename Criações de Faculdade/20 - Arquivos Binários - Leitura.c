#include <stdio.h>
#include <stdlib.h>

struct Num {
    int n1, n2;
};

int main() {
    struct Num obj;
    FILE *fptr;

	//Leitura de arquivo binário
    if ((fptr = fopen("mbl.bin", "rb")) == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

	int n;
    for (n = 1; n < 10; ++n) {
    	//Lê a estrutura num do arquivo e armazena na variável obj
        fread(&obj, sizeof(struct Num), 1, fptr);
        printf("n1: %d\tn2: %d\n", obj.n1, obj.n2);
    }

    fclose(fptr);
    return 0;
} 

