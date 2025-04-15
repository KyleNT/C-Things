
// Programa em C para ler conteúdos de um arquivo
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[80];
    FILE* ptr;

    ptr = fopen("Hello.txt", "r");

    if (ptr == NULL) {
        printf("Erro ao abrir o arquivo");
        // Se o ponteiro retornar NULL, o programa será encerrado
        exit(1);
    }
    
    if (fgets(str, 80, ptr) != NULL) {
        puts(str); // Exibe a string lida
    }

    fclose(ptr);

    return 0;
} 
