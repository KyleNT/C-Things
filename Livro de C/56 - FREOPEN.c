#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	FILE *fp;
	
	printf("Mostrado na tela");
	
	if((fp=freopen("NILF.txt", "w", stdout))==NULL) {
		printf("O arquivo nao pode ser aberto.\n");
		exit(1);
	}
	
	printf("Isso sera escrito no arquivo NILF.");
	
	fclose(fp);
}
