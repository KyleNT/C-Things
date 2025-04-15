#include <stdio.h>

void syntax_error(int num);
void display_array(int *q[], int tam);

void main(void){
	int a = 1, b = 2, c = 3;
	int *Arr[] = {&a, &b, &c};
	int erro = 0;
	int tam = sizeof(Arr) / sizeof(Arr[0]);
	syntax_error(erro);
	display_array(Arr, tam);
}

void syntax_error(int num){
	static char *err[] = {
		"Arquivo nao encontrado\n",
		"Erro de leitura\n",
		"Erro de escrita\n",
		"Falha da midia\n"
	};
	
	printf("%s", err[num]);
}

void display_array(int *q[], int tam){
	int t;
	//Quando for declarar um endereço de ponteiro, é sempre sem o caractere de ponteiro
	for (t=0; t<tam; t++){
		printf("Endereço: %p, valor: %d \n", q[t], *q[t]);
	}
}
