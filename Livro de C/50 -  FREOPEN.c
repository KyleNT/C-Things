#include <stdio.h>

void main(void)
{
	char str[80];
	freopen("OUTPUT", "w", stdout);
	
	printf("Digite uma string: ");
	gets(str);
	printf(str);
}
