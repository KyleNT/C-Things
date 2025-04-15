#include <stdio.h>
#include <stdlib.h>

int main (){
	
	char variavel[] = "";
	int inteiro = 0;
	double racional = 0.0;
	double op1, op2;
	char operador;
	//	char str1[10], str2[10], str3[10];
	// 	int year;
	// 	FILE * fp;
	
	//String
	printf("Bem vindo ao Digitador em C, digite alguma coisa: ");
	scanf("%s", variavel);
	
	//Inteiro
	printf("\nDigite um inteiro e racional: ");
	scanf("%i %Le", &inteiro,&racional);
	
	//Teste de Operacoes
	printf("\nEntre com (1) Numero, (2) +, -, *, /, (3) Numero\n");
	while(scanf("%Le %c %Le", &op1, &operador, &op2)==3){
		switch(operador){
			case '+': printf("%g\n", op1+op2); break;
			case '-': printf("%g\n", op1-op2); break;
			case '*': printf("%g\n", op1*op2); break;
			case '/': printf("%g\n", op1/op2); break;
			default: printf("Operador Invalido! \n");	
		}
		printf("Entre com (1) Numero, (2) +, -, *, /, (3) Numero\n");
	}
	
	//						Teste de fscanf
	//	fp = fopen ("file.txt", "w+");
	//	fputs("Nos estamos em 2022", fp);
	//	rewind(fp);
	//	fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);
   
	//	printf("------------- Leitura -------------\n");
	//	printf("Leitura de String N. 1 |%s|\n", str1 );
	//	printf("Leitura de String N. 2 |%s|\n", str2 );
	//	printf("Leitura de String N. 3 |%s|\n", str3 );
	//	printf("Leitura de Integer |%d|\n", year );

	//	fclose(fp);
	
	printf("------------- Coletado -------------\n");
	printf("Digitado: %s\n", variavel);
	printf("\nDigitado os numero inteiro: %d, Racional: %e\n", inteiro, racional);
	system("PAUSE");
	return 0;
}
