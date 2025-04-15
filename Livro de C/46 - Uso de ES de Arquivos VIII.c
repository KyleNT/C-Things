#include <stdio.h>
#include <stdlib.h>

void main(void){
	FILE *fp;
	double d = 12.23;
	int i = 101;
	long l = 123923L;
	
	if((fp=fopen("gpl.bin", "wb+"))==NULL){
		printf("O arquivo nao pode ser aberto. \n");
		exit(1);
	}
	
	fwrite(&d, sizeof(double), 1, fp);
	fwrite(&i, sizeof(int), 1, fp);
	fwrite(&l, sizeof(long), 1, fp);
	
	rewind(fp);
	
	fread(&d, sizeof(double), 1, fp);
	fread(&i, sizeof(int), 1, fp);
	fread(&l, sizeof(long), 1, fp);
	
	printf("%f %d %ld", d, i, l);
	fclose(fp);
}
