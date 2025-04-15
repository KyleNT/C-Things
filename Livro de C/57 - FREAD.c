#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *fp;
	float mm[10];
	
	if((fp=fopen("mms.bin", "rb"))==NULL) {
		printf("O arquivo nao pode ser aberto.\n");
		exit(1);
	}
	
	if(fread(mm, sizeof(float), 10, fp) != 10) {
		if(feof(fp)) printf("Fim de arquivo prematuro.");
		else printf("Erro na leitura do arquivo.");
	}
	
	fclose(fp);
}
