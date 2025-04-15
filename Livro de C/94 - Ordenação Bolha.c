#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bulle(char *item, int count);

void main(void)
{
	char s[350];
	clock_t start, end;
    double cpu_time_used;
	

	printf("Digite uma string: ");
	gets(s);
	start = clock();
	bulle(s, strlen(s));
	end = clock();
	
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	
	printf("Tamanho da String: %d \n", strlen(s));
	printf("A string ordenada e: '%s'\n", s);
	printf("O ordenacao bolha durou usou %.6f segundos. \n", cpu_time_used);
}

void bulle(char *item, int count)
{
	register int a,b;
	register char t;
	
	for(a=1; a<count; ++a)
		for(b=count-1; b>=a; --b){
			if(item[b-1] > item[b]) {
				t = item[b-1];
				item[b-1] = item[b];
				item[b] = t;
			}
		}
}
