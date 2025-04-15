// Programa em C para criar um arquivo
#include <stdio.h> //Biblioteca padr�o
#include <stdlib.h> //Biblioteca com fun��es exit()

int main() {
    FILE *ptr; //Ponteiro do Arquivo
    ptr = fopen("./Hello.txt", "w"); //Abre ou criar um arquivo de escrita

	//Verifica se teve algum erro
    if (ptr == NULL) {
        printf("Erro ao criar o arquivo!"); //Se tiver erro, solte um n�mero
        exit(1); //Encerra com status de erro
    }

    char str[] = "Dados a serem inseridos no arquivo.";
    fputs(str, ptr);
    
    fclose(ptr); //Fecha o arquivo
    printf("Arquivo criado\n\n");
    printf("%s\n\n", str);

    return 0;
}
