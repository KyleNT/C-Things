#include <stdio.h>
#include <math.h>

void absoluto(double arg, double arg2);
void maior_inteiro(double num);
void modulo(double x, double y);
void mantissa(double man);

void main (void){
	double arg, arg2, x, y, man;
	
	arg = -1.0;
	arg2 = 1.0;
	x = 10;
	y = 3;
	man = 10;
	
	absoluto(arg, arg2);
	maior_inteiro(10.9);
	modulo(x, y);
	mantissa(man);
	
}

void absoluto(double arg, double arg2){
	double val = arg;
	printf("\n### VALOR ABSOLUTO ### \n");
	printf("Valores absolutos de %f e %f. \n", fabs(val), fabs(arg2));

}

void maior_inteiro(double num){
	printf("### MAIOR INTEIRO ### \n");
	printf("%f \n", floor(num));
}

void modulo(double x, double y){
	printf("\n### MODULO ### \n");
	printf("O modulo da divisao de %f e %f e igual a %f. \n", x, y, fmod(x,y));

}

void mantissa(double man){
	int expt;
	double fabr = frexp(man, &expt);
	printf("\n### MANTISSA ### \n"); //man = mantissa * 2^EXPOENTE
	printf("Valor da mantissa %f, expoente %d. \n", fabr, expt);
	
}
