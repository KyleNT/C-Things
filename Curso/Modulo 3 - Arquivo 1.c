#include <stdio.h>
#include <locale.h>
int main(){
	
	setlocale(LC_ALL, "Portuguese");
	/*
	int idade;
	
	printf("Digite a idade: ");
	scanf("%d", &idade);
	
	if(idade > 17){
		printf("Maior de Idade, %d",idade);
	} else if (idade == 18){
		printf("%d, DEZOITO ANOS", idade);
	}else {
		printf("Menor de Idade, %d",idade);
	}
	*/
	
	int paral;
	printf("Digite o numero: ");
	scanf("%d", &paral);
	
	if(paral % 2 == 0){
		printf("� par");
	} else {
		printf("� impar");
	}
	return 0;
}
