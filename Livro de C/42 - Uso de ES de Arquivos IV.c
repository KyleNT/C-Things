#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{
	char str[144];
	FILE *fp;
	
	if((fp = fopen("gtl.txt", "w"))==NULL){
		printf("O arquivo nao pode ser aberto. \n");
		exit(1);
	}
	
	do{
		printf("Digite uma string (CR para sair): \n");
		gets(str);
		strcat(str, "\n");
		fputs(str, fp);
	} while(*str!='\n');
	
	fclose(fp);
}
