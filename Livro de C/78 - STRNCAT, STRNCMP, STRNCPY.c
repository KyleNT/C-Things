#include <stdio.h>
#include <string.h>

#define SIZE 80

void string_ncat(void);
void string_ncmp(int argc, char *argv[]);
void string_ncpy(void);

void main (int argc, char *argv[])
{
	string_ncat();
	string_ncmp(argc, argv);
	string_ncpy();
}

void string_ncat(void){
	char s1[SIZE], s2[SIZE];
	unsigned int len;
	
	gets(s1);
	gets(s2);
	
	len = (SIZE-1)-strlen(s2);
	strncat(s2, s1, len);
	printf("%s \n", s2);	
}

void string_ncmp(int argc, char *argv[]){
	if(argc!=3) {
		printf("Numero incorreto de parametros \n");
		exit(1);
	}
	if(!strncmp(argv[1], argv[2], 0))
		printf("Os nomes de arquivo sao iguais. \n");
}

void string_ncpy(void){
	char str1[SIZE], str2[SIZE];
	
	gets(str1);
	strncpy(str2, str1, 79);
	printf(str2);
}
