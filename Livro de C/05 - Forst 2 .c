#include <stdio.h>
#include <string.h>

void main(void){
	char s[105], *str;
	int space;
	
	printf("Digite uma string: ");
	
	gets(s);
	str = s;
	
	for(space = 0; *str; str++){
		if(*str != ' ') continue;
		space++;
	}
	
	printf("%d espaços\n", space);
}
