#include <stdio.h>
#include <locale.h>
int main(){
	
	setlocale(LC_ALL, "Portuguese");
	/*
	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);
	
	
	if(a > 10 && b > 10 && c > 10){
		printf("Todos s�o maiores que 10");
	} else {
		printf("Um dos valores � menor que 10");
	}
	
	
	if(a > 10 || b > 10 || c > 10){
		printf("Todos s�o maiores que 10");
	} else {
		printf("Um dos valores � menor que 10");
	}
	*/
	printf("Menu \t \n");
	printf("1 - Touhou 6 \t \n");
	printf("2 - Touhou 7 \t \n");
	printf("3 - Touhou 8 \t \n");
	printf("Escolha uma op��o: \n");
	
	int opt;
	scanf("%d", &opt);
	
	switch(opt){
		case 1:
			printf("Touhou 6 escolhido");
			break;
		case 2:
			printf("Touhou 7 escolhido");
			break;	
		case 3:
			printf("Touhou 8 escolhido");
			break;	
		default:
			printf("N�o encontrado");
			break;
	}
	return 0;
	
}
