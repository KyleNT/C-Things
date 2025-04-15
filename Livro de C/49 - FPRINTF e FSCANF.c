#include <stdio.h>
#include <io.h>
#include <stdlib.h>

void main(void){
	FILE *fp;
	char s[100];
	int t;
	
	if((fp=fopen("Lilien.txt", "w")) == NULL) {
		printf("O arquivo nao pode ser aberto. \n");
		exit(1);
	}
	
	printf("Digite uma string e um numero: ");
	fscanf(stdin, "%s%d", s, &t);
	
	fprintf(fp, "%s %d", s, t);
	fclose(fp);
	
	if((fp=fopen("Lilien.txt", "r")) == NULL) {
		printf("O arquivo nao pode ser aberto. \n");
		exit(1);
	}
	
	fscanf(fp, "%s%d", s, &t);
	fprintf(stdout, "%s %d", s, t);
}
