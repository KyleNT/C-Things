#include <stdio.h>

//Argumento em String
#define mkstr(s) #s

//Concatena duas palavras
#define concat(a,b) a ## b

void main(void){
	int xy = 10;
	printf(mkstr(Was wollen wir trinken));
	printf("\n %d \n", concat(x, y));
}
