#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
	int outcome, len, l1, l2;
	
	if(argc!=3) {
		printf("Numero incorreto de parametros");
		exit(1);
	}
	
	l1 = strlen(argv[1]);
	l2 = strlen(argv[2]);
	len = l1 < l2 ? l1 : l2;
	
	outcome = memcmp(argv[1], argv[2], len);
	if(!outcome) printf("\n Iguais");
	else if(outcome<0) printf("\n Primeiro menor que o segundo.");
	else printf("\n Primeiro maior que o segundo");
}
