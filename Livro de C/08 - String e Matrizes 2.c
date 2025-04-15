#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num[10][10];

void pr_row(int j);
void pr_row_2(int k, int row_dimension, int *p);

const char* bomdia();

const char* bomdia(){
	return "Bom dia!";
}

void main(void){
	int *k, i[10];
	char bom_dia[100];
	
	strcpy(bom_dia, bomdia());
	
	k = i;
	
	k[5] = 1948;
	*(k+6) = 1952;
	
	//Pense em uma matriz a[10][10]
	//a[0][9] = 9ª Vetor
	//a[1][0] = 10º Vetor
	//a[1][1] = 11º Vetor
	//a[1][2] = 12º Vetor
	//logo, *(a+12) = a[1][2]
	//a[j][k] = *(a+(j x comprimento de linhas)+k)
	
	printf("%d \n", i[5]);
	printf("%d \n", i[6]);
	
	//printf("%s", bom_dia);
	pr_dizer(bom_dia);
	system("pause");
	
	
}

void pr_row(int j){
	
	int *p, t;
	
	p = &num[j][0];
	
	for(t=0; t<10; ++t) printf("%d ", *(p+t));
}

void pr_row_2(int k, int row_dimension, int *p){
	int t;
	
	p = p + (k * row_dimension);
	
	for(t=0; t<row_dimension; ++k)
		printf("%d ", *(p+t));
}

void pr_dizer(char str[]){
  int t;
  char *k;
  char strtmp[100]; 
  strcpy(strtmp, str);
  k = &strtmp[0];
  for(t=0; t<strlen(str); ++t) printf("%c", *(k+t));
  printf("\n");
}
