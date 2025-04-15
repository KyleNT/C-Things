#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection(char *item, int count);

void main(void)
{
	char s[350];
	clock_t start, end;
    double cpu_time_used;
	

	printf("Digite uma string: ");
	gets(s);
	start = clock();
	selection(s, strlen(s));
	end = clock();
	
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	
	printf("Tamanho da String: %d \n", strlen(s));
	printf("A string ordenada e: '%s'\n", s);
	printf("O ordenacao por selecao durou usou %.6f segundos. \n", cpu_time_used);
}

void selection(char *item, int count)
{
	register int a,b,c;
	int exchange;
	char t;
	
	for(a = 0; a<count-1; ++a){
		exchange = 0;
		c = a;
		t = item[a];
		for(b=a+1; b<count; ++b){
			if(item[b]<t){
				c = b;
				t = item[b];
				exchange = 1;
			}
		}
		if(exchange){
			item[c] = item[a];
			item[a] = t;
		}
	}
}
