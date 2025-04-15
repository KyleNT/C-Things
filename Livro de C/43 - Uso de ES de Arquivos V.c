#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void){
	char str[144];
	FILE *fp;
	
	if((fp = fopen("gnl.txt", "w+"))==NULL){
		printf("O arquivo nao pode ser aberto. \n");
		exit(1);
	}
	
	do{
		printf("Digite uma string (CR ou Enter para sair): \n");
		gets(str);
		strcat(str, "\n");
		fputs(str, fp);
	} while(*str!='\n');
	
	rewind(fp);
	
	while(!feof(fp)){
		fgets(str, 143, fp);
		printf(str);
	}
	
	fclose(fp);
}
