#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void main(int argc, char *argv[]){
	int disp, count;
	
	if(argc<2){
		printf("Voce deve digitar o valor a contar\n");
		printf("na linha de comando. Tente novamente!\n");
		exit(1);
	}
	
	if(argc==3 && !strcmp(argv[2], "display")) disp = 1;
	else disp = 0;
	
	for(count=atoi(argv[1]); count; --count)
		if(disp) printf("%d \n", count);
		
	putchar('\a');
	
	printf("Terminou");
}
