#include <stdio.h>
#include <string.h>

void main(void){
	char str[100];
	
	gets(str);
	printf("O comprimento e: %d", strlen(str));
}
