#include <stdio.h>
#include <math.h>

void potencia(double base, double exp);
void seno(double arg);
void seno_hiperbolico(double arg);
void raiz_quadrada(double num);

void main (void){
	double arg, arg2;
	
	arg = -1.0;
	arg2 = 16;
	
	potencia(10,0);
	seno(arg);
	seno_hiperbolico(arg);
	raiz_quadrada(arg2);
	
}

void potencia(double base, double exp){
	double x, y;
	x = base;
	y = exp;
	printf("### POTENCIA ### \n");
	
	do{
		printf("%f elevado a %f e %f \n", x, y, pow(x, y));
		y++;
	} while(y<11.0);
	
}

void seno(double arg){
	double val = arg;
	printf("\n### SENO (RAD) ### \n");
	do{
		printf("Seno de %f e %f. \n", val, sin(val));
		val += 0.1;
	} while(val<=1.0);
}

void seno_hiperbolico(double arg){
	double val = arg;
	printf("\n### SENO HIPERBOLICO ### \n");
	do{
		printf("Seno hiperbolico de %f e %f. \n", val, sinh(val));
		val += 0.1;
	} while(val<=1.0);	
}

void raiz_quadrada(double arg2){
	printf("\n### RAIZ QUADRADA ### \n");
	printf("Raiz de %f e %f. \n", arg2, sqrt(arg2));
	
}
