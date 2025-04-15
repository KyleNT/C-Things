#include <stdio.h>
#include <math.h>

void tangente(double arg);
void tangente_hiperbolica(double arg);

void main (void){
	double arg;
	
	arg = -1.0;

	tangente(arg);
	tangente_hiperbolica(arg);
}

void tangente(double arg){
	double val = arg;
	printf("\n### TANGENTE (RAD) ### \n");
	do{
		printf("Tangente de %f e %f. \n", val, tan(val));
		val += 0.1;
	} while(val<=1.0);
}

void tangente_hiperbolica(double arg){
	double val = arg;
	printf("\n### TANGENTE HIPERBOLICA ### \n");
	do{
		printf("Tangente hiperbolica de %f e %f. \n", val, tanh(val));
		val += 0.1;
	} while(val<=1.0);	
}
