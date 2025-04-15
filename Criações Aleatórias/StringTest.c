#include <stdio.h>
#include <math.h>

int main(){
	
	double a = 0.0, b = 0.0, c = 0.0;
	
	printf("Digite Cateto Oposto: ");
	scanf("%lf", &b);
	
	printf("\nDigite Cateto Adjacente: ");
	scanf("%lf", &c);
	
	a = sqrt(pow(b,2) + pow(c,2));
	
	printf("\n Resultado: %.2lf", a);
	
	}
