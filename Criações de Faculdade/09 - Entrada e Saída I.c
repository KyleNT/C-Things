#include <stdio.h>
#include <string.h>

int main(void){
	
	char string[80];
	
	char stringola[12];
	
	printf("Digite o texto hiperborico: ");
	
	
	fgets(string, sizeof(string), stdin);
	
	printf("Digite o texto 17h: ");
	
	scanf("%s", stringola);
	
	printf("\nO comprimento e %d\n", strlen(string));
	printf("\nA String inserida e: %s \n", stringola);
	
	return 0;
}
