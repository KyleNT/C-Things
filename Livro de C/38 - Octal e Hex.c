#include <stdio.h>
#include <stdlib.h>
void main(void)
{
	int i, j, k, x, y;
	char str[80], str2[80], str3[80], str4[80];
	
	//Octal e Hex
	scanf("%o%x%*[^\n]",&i, &j);
	printf("%8o %8x %8d %8d \n", i, j, i, j); //12 12
	fflush(stdin);
	
	scanf("%d%[abcdefg]%s%*[^\n]", &k,str, str2); //Até uma parte da string, pode ser também %[A-Z] ou %20s
	printf("%d %s %s \n", k, str, str2); //123abcdtye
	fflush(stdin);
	
	scanf("%[a-z]%*[^\n]", str3);
	printf("%s \n", str3); //aba
	fflush(stdin);
	
	scanf("%8s%*[^\n]", str4);
	printf("%s \n", str4); //agora
	fflush(stdin);
	
	scanf("%d%*c%d", &x, &y);
	printf("%d,%d \n",x,y); //10,10
	fflush(stdin);
	system("pause");
}
