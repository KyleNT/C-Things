#include <stdio.h>
#include <stdlib.h>

int main(){
	/*
	float a;
	float b;
	
	float resultado;
	
	printf("Digite o valor float a: ");
	scanf("%f", &a);
	printf("Digite o valor float b: ");
	scanf("%f", &b);
	
	resultado = (a*b)/2;
	
	printf("Resultado: %f", resultado);
	*/
	//o & � para o endere�o de mem�ria
	
	//inteiro: %d
	//float: %f
	//Letra: %c
	
	//fflush(stdin) limpe a entrada - Windows
	//__fpurge(stdin) limpe que est� na entrada principal
	char a;
	char b;
	
	scanf("%c", &a);
	fflush(stdin); //limpa buffer
	scanf("%c", &b);
	//Voc� pode usar o flush novamente, mas quando compila e acaba limpando. Tecnicamente n�o precisa.
	
	printf("Resultado: %c %c", a, b);
	
	return 0;
}
