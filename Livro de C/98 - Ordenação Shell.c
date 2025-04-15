#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sabot(char *item, int count);

void main(void)
{
	char s[350];
	clock_t start, end;
    double cpu_time_used;
	

	printf("Digite uma string: ");
	gets(s);
	start = clock();
	sabot(s, strlen(s));
	end = clock();
	
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	
	printf("Tamanho da String: %d \n", strlen(s));
	printf("A string ordenada e: '%s'\n", s);
	printf("O ordenacao shell durou usou %.6f segundos. \n", cpu_time_used);
}

void sabot(char *item, int count)
{
	register int i, j, gap, k;
	char x, a[5];
	
	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
	
	for(k=0; k<5; k++){
		gap = a[k];
		for(i = gap; i<count; ++i){
			x = item[i];
			for(j=i-gap; x<item[j] && j>=0; j=j-gap)
				item[j+gap] = item[j];
			item[j+gap] = x;
		}
	}
}
