#include <stdio.h>
#include <math.h>

void menor_inteiro(double num);
void cosseno(double arg);
void cosseno_hiperbolico(double arg);
void e_elevado_a(double arg2);

void main (void){
	double arg, arg2;
	
	arg = -1.0;
	arg2 = 1.0;
	
	menor_inteiro(9.9);
	cosseno(arg);
	cosseno_hiperbolico(arg);
	e_elevado_a(arg2);
	
}

void menor_inteiro(double num){
	printf("### MENOR INTEIRO ### \n");
	printf("%f \n", ceil(num));
}

void cosseno(double arg){
	double val = arg;
	printf("\n### COSSENO (RAD) ### \n");
	do{
		printf("Cosseno de %f e %f. \n", val, cos(val));
		val += 0.1;
	} while(val<=1.0);
}

void cosseno_hiperbolico(double arg){
	double val = arg;
	printf("\n### COSSENO HIPERBOLICO ### \n");
	do{
		printf("Cosseno hiperbolico de %f e %f. \n", val, cosh(val));
		val += 0.1;
	} while(val<=1.0);	
}

void e_elevado_a(double arg2){
	printf("\n### LOGARITMO NATURAL E ELEVADO A TAL POTENCIA ### \n");
	printf("Valor de E elavado a %f e %f. \n", arg2, exp(arg2));
	
}
