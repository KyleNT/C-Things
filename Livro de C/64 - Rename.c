#include <stdio.h>

void main(int argc, char *argv[])
{
	if(rename(argv[1], argv[2])!=0)
		printf("Erro na troca de nomes");
}
