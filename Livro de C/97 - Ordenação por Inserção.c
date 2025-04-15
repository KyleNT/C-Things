#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion(char *item, int count);

void main(void)
{
	char s[350];
	clock_t start, end;
    double cpu_time_used;
	

	printf("Digite uma string: ");
	gets(s);
	start = clock();
	insertion(s, strlen(s));
	end = clock();
	
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	
	printf("Tamanho da String: %d \n", strlen(s));
	printf("A string ordenada e: '%s'\n", s);
	printf("O ordenacao por insercao durou usou %.6f segundos. \n", cpu_time_used);
}

void insertion(char *item, int count)
{
	register int a,b;
	char t;
	
	for(a=1; a<count; ++a){
		t = item[a];
		for(b=a-1; b>= 0 && t<item[b]; b--)
			item[b+1] = item[b];
		item[b+1] = t;
	}
}
