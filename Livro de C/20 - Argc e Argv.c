#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]){
	if(argc!=2){
		printf("Esqueceu de botar o nome. \n");
		//exit(1);
	}
	printf("Ola %s \n", argv[1]);
	printf("Número de argumentos: %d\n", argc);
	int i;
    for (i = 0; i < argc; i++) {
        printf("Argumento %d: %s\n", i, argv[i]);
    }
    return 0;
}
