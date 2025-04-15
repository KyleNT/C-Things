// Programa C para gravar em um arquivo bin�rio
#include <stdio.h>
#include <stdlib.h>

//Uma estrutura chamada num que contem 2 inteiros
struct Num {
    int n1, n2;
};

int main() {
    struct Num obj; //Declara��o do Struct num
    FILE *fptr; //Declara��o de um ponteiro para oa arquivo

	//Abre ou cria um arquivo bin�rio chamando "MBL.bin" no modo de escrita bin�ria
    if ((fptr = fopen("mbl.bin", "wb")) == NULL) {
    	//Verifica se teve erro em abrir ou criar o arquivo
        printf("Erro ao abrir o arquivo");
        //Se fptr for NULL, imprime o erro e fecha o programa
        exit(1); //Fecha em status de erro
    }

	//Loop para escrita de dados bin�rios
	int n;
    for (n = 1; n < 10; n++) {
        obj.n1 = n; //Atribui o valor n a n1 da estrutura
        obj.n2 = 13 + n; //Atribui o valor 14 + n a n2 da esturutra
        //Escreve a estrutura obj do arquivo
        //fwrite escreve 1 no bloco de dados do tamanho de struct Num
        fwrite(&obj, sizeof(struct Num), 1, fptr);
    }

	//Fecha o arquivo
    fclose(fptr);
    
    //Imprime a mensagem caso tenha sido gravado com sucesso
    printf("Dados gravados no arquivo bin�rio\n\n");

    return 0;
} 
