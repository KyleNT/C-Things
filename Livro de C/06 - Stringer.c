#include <stdio.h>
#include <string.h>

void main(void){
	char s1[80], s2[80];
	
	gets(s1);
	gets(s2);
	printf("Comprimentos: %d e %d \n", strlen(s1), strlen(s2));
	strcat(s1, s2);
	printf("%s\n", s1);
	strcpy(s1, "Isso é um teste\n");
	printf(s1);
	if(strchr("alo",'o')) printf("o esta em alo");
	if(strstr("ola aqui", "ola")) printf("ola encontrado");
}
