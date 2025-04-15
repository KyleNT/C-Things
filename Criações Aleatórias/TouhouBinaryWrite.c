// Programa C para gravar em um arquivo binário
#include <stdio.h>
#include <stdlib.h>

//Uma estrutura chamada num que contem 2 inteiros
struct Krause {
    int krause_1, krause_2;
    char kreis[50];
};

int main() {
    struct Krause klaus; //Declaração do Struct num
    FILE *fptr; //Declaração de um ponteiro para oa arquivo

	//Abre ou cria um arquivo binário chamando "MBL.bin" no modo de escrita binária
    if ((fptr = fopen("krupp.bin", "wb")) == NULL) {
    	//Verifica se teve erro em abrir ou criar o arquivo
        printf("Erro ao abrir o arquivo");
        //Se fptr for NULL, imprime o erro e fecha o programa
        exit(1); //Fecha em status de erro
    }

	//Loop para escrita de dados binários
	int n;
    for (n = 0; n < 3; n++) {
        klaus.krause_1 = n; //Atribui o valor n a n1 da estrutura
        klaus.krause_2 = 1 + n; //Atribui o valor 14 + n a n2 da esturutra
        
        switch(n){
        	case 0:
        		strcpy(klaus.kreis, "Reimu Hakurei");
        	break;
        	
        	case 1:
          		strcpy(klaus.kreis, "Marisa Kirisame");
        	break; 
			
			case 2:
          		strcpy(klaus.kreis, "Sakuya Izayoi");
        	break;     		
        	
        	default:
        		strcpy(klaus.kreis, "Undefined");
        	break;
        	
		}
        //Escreve a estrutura obj do arquivo
        //fwrite escreve 1 no bloco de dados do tamanho de struct Num
        fwrite(&klaus, sizeof(struct Krause), 1, fptr);
    }

	//Fecha o arquivo
    fclose(fptr);
    
    //Imprime a mensagem caso tenha sido gravado com sucesso
    printf("Successful binary writing!\n\n");

    return 0;
} 
