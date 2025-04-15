#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void oscillant(char *item, int count);

void main(void)
{
	char s[350];
	clock_t start, end;
    double cpu_time_used;
	

	printf("Digite uma string: ");
	gets(s);
	start = clock();
	oscillant(s, strlen(s));
	end = clock();
	
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	
	printf("Tamanho da String: %d \n", strlen(s));
	printf("A string ordenada e: '%s'\n", s);
	printf("O ordenacao oscilante durou usou %.6f segundos. \n", cpu_time_used);
}

void oscillant(char *item, int count)
{
	register int a;
	int exchange;
	char t;
	
	do{
		exchange = 0;
		for(a=count-1; a>0; --a){
			if(item[a-1]>item[a]){
				t = item[a-1];
				item[a-1] = item[a];
				item[a] = t;
				exchange = 1;
			}
		}
		
		for(a=1; a<count; ++a){
			if(item[a-1]>item[a]){
				t = item[a-1];
				item[a-1] = item[a];
				item[a] = t;
				exchange = 1;
			}
		}
	} while(exchange); //Ordena até onde não pode mais
}
