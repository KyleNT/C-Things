#include <stdio.h>
#include <string.h>

void string_str(void);
void string_tok(void);
void string_xfrm(void);

void main(void)
{
	string_str();
	string_tok();
	string_xfrm();
}

void string_str(void){
	char *p;
	p = strstr("isto e um teste", "to");
	printf("%s \n",p);
}

void string_tok(void){
	char *p;
	char str[] = "1980 U.S. Elections, November 1980";
	const char delim[] = " ";
	p = strtok(str, delim);
	printf(p);
	do{
		p = strtok('\0', ", ");
		if(p) printf("|%s", p);
	} while(p);
	printf("\n");
}

void string_xfrm(void){
	char str1[80], str2[80];
	strcpy(str1, "1972 U.S. Presidential Elections");
	//printf("%s", str1);
	printf("%d", strxfrm(str2, str1, 10));
}
