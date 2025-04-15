#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rapide(char *item, int count);
void trirapide(char *item, int left, int right);

void main(void)
{
	char s[350];
	clock_t start, end;
    double cpu_time_used;
	

	printf("Digite uma string: ");
	gets(s);
	start = clock();
	rapide(s, strlen(s));
	end = clock();
	
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	
	printf("Tamanho da String: %d \n", strlen(s));
	printf("A string ordenada e: '%s'\n", s);
	printf("O ordenacao shell durou usou %.6f segundos. \n", cpu_time_used);
}

void rapide(char *item, int count)
{
	trirapide(item, 0, count-1);
}

void trirapide(char *item, int left, int right){
	register int i, j;
	char x, y;
	
	i = left; j = right;
	x = item[(left+right)/2];
	
	do{
		while(item[i]<x && i<right) i++;
		while(x<item[j] && j>left) j--;
		
		if(i<=j) {
			y = item[i];
			item[i] = item[j];
			item[j] = y;
			i++; j--;
		}
	} while (i<=j);
	
	if(left<j) trirapide(item, left, j);
	if(i<right) trirapide(item, i, right);
}
