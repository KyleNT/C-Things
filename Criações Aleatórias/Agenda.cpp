#include <stdio.h>
#include <stdlib.h>

// Agenda de Aniversários

typedef struct{
	char nome[60];
	int dia, mes, ano;
	char detalhes[800];
}Contatus;

void imprimir(Contatus **c, int quant){
	int i;
	printf("\n\t\tLista de Contatos:\n");
	printf("\t--------------------------------\n");
	for(i = 0; i<quant;i++){
		printf("\t%d = %2d/%2d/%4d\t%s\t%s\n", i+1, c[i]->dia, c[i]->mes,c[i]->ano, c[i]->nome, c[i]->detalhes);
	}
	printf("\t--------------------------------\n");
}

int cad_contatus(Contatus **c, int quant, int tam){
	if (quant < tam){
		Contatus *novo = malloc(sizeof(Contatus));
		
		printf("\nDigite o nome do contato: ");
		scanf("%s", novo->nome);
		printf("\nDigite um texto relacionado (800 caracteres): ");
		scanf("%s", novo->detalhes);
		printf("\nDigite a data de aniversario (dd mm aaaa): ");
		scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
		getchar();
		c[quant] = novo;
		return 1;
	} else {
		printf("\n\t Vetor cheio \n");
		return 0;
	}
}

void alt_contatus(Contatus **c, int quant){
	int id;
	imprimir(c, quant);
	
	printf("\n\t Digite o codigo do contato para ser alterado: \n");
	scanf("%d", &id);
	getchar();
	id--;
	
	if(id >= 0 && id < quant){
		Contatus *novo = malloc(sizeof(Contatus));
		
		printf("\nDigite o nome do contato: ");
		scanf("%s", novo->nome);
		printf("\nDigite um texto relacionado (800 caracteres): ");
		scanf("%s", novo->detalhes);
		printf("\nDigite a data de aniversario (dd mm aaaa): ");
		scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
		getchar();
		c[id] = novo;
	} else{
		printf("\n\tCodigo invalido!\n");
	}
}

void salvar(Contatus **c, int quant, char arq[])[
FILE *file = fopen(arq, "w");
int i;

if(file){
	fprintf(file, "%d\n" quant);
	for(i = 0; i < quant; i++){
		fputs(c[i]->nome, file);
		fputs("\n", file);
		fprintf(file, "%d %d %d\n\t%s", c[i]->dia, c[i]->mes, c[i]->ano, c[i]->detalhes);
		
	}
	fclose(file);
} else {
	printf("\n\t Impossivel criar/abrir arquivo");
}

int main(){
	Contatus *agenda[60];
	int opcao, tam = 60, quant = 0;
	
	do{
		
		printf("\n\t0 - Sair\n\t1 - Cadastrar\n\t2 - Alterar\n\t3 - Imprimir\n\t4 - Salvar\n\t5 - Ler arquivo\n");
		scanf("%d", &opcao);
		getchar();
		
		switch(opcao){
			case 1:
				quant += cad_contatus(agenda, quant, tam);
				break;
			case 2:
				alt_contatus(agenda, quant);
				break;
			case 3:
				imprimir(agenda, quant);
				break;
			case 4:
				salvar(agenda, quant, arquivo);
				break;
			case 5:
				break;
			default:
				if(opcao != 0){
					printf("\n\tOpcao invalida\n");
				}
				break;
		}
	} while(opcao != 0);
	
	return 0;
}
