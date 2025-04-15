#include <stdio.h>
#include <stdlib.h>
/*FUNÇÃO VOID
void macaco(char macacal[]){
	puts(macacal); //Função VOID
}
*/
/* Função Escopo
int ag = 12;
void macaco2(){
	int a = 10;
	printf("Valor de A: %d \n", a);
	ag = 17;
}
*/
/*Função Recursiva*/
/*
int valor = 0;
void add1para10(){
	if(valor < 10){
		printf("%d \n", valor);
		valor++;
		add1para10();
	}
}
*/

/*Função com Retorno*/
/*
int retorna10(){
	int a = 10;
	return a;
}
*/

/*Função com Parâmetro
int retornaSoma(int a, int b){
	int soma = a + b;
	return soma;
}
*/

/* Structs */
typedef struct {
	int idade;
	float salario;
	char nome[255];
} Pessoa;

int main(){
	
	/* Arquivo 6 - 1: Funções VOID
	char macacal[255] = "";

	fgets(macacal, sizeof(macacal), stdin);
	fflush(stdin);
	macaco(macacal);
	*/
	
	/*Arquivo 6 - 2: Escopo Local e Global
	//Amplitude de espaço onde pode ser usada, se for fora da função main é Global, se for dentro de uma função, é Local
	int a = 15;
	printf("Valor de A Global: %d \n", ag);
	macaco2();
	printf("Valor de A: %d \n", a);
	printf("Novo Valor de A Global: %d", ag);
	*/
	
	/*Arquivo 6 - 3: Recursão
	
	add1para10();
	printf("Fim");
	*/
	
	/*Arquivo 6 - 4: Função com retorno
	printf("Retorna: %d", retorna10());
	 */
	 
	/*Arquivo 6 - 5: Função com parâmetros*/
	/*
	int valor1, valor2;
	printf("Insira dois numeros: ");
	scanf("%d %d",&valor1,&valor2);
	printf("\n Resultado da Soma: %d", retornaSoma(valor1,valor2));
	*/
	
	/*Arquivo 6 - 6: Structs*/
	Pessoa pessoa1;
	printf("Digite a Idade: ");
	scanf("%d",&pessoa1.idade);
	pessoa1.salario = 500.0;
	strcpy(pessoa1.nome, "Struct");
	
	printf("Nome: %s \n", pessoa1.nome);
	printf("Idade: %d anos, Salario: %.2f", pessoa1.idade,pessoa1.salario);
	
	return 0;
}
