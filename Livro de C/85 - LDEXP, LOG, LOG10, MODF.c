#include <stdio.h>
#include <math.h>

void mantissa_vezes_2_elev_exp(double num, int exp);
void logaritmo_natural(double num);
void logaritmo_base_10(double num);
void inteiro_fracionario(double num);

void main (void){

	mantissa_vezes_2_elev_exp(1, 2);
	logaritmo_natural(1.0);
	logaritmo_base_10(1.0);
	inteiro_fracionario(10.123);
	
}

void mantissa_vezes_2_elev_exp(double arg, int exp){
	double val = arg;
	printf("\n### MANTISSA VEZES DUAS VEZES O EXPOENTE ### \n");
	printf("%f * 2^%d: %f \n", arg, exp, ldexp(arg, exp));

}

void logaritmo_natural(double num){
	printf("### LOGARITMO NATURAL ### \n");
	double val = num;
	
	do{
		printf("Logaritmo natural de %f e igual a %f \n", val, log(val));
		val++;
	} while(val<11.0);
}

void logaritmo_base_10(double num){
	printf("### LOGARITMO DE BASE 10 ### \n");
	double val = num;
	
	do{
		printf("Logaritmo de base 10 de %f e igual a %f \n", val, log10(val));
		val++;
	} while(val<11.0);

}

void inteiro_fracionario(double man){
	double i;
	double f;
	
	f = modf(man, &i);
	
	printf("\n### DECOMPOR INTEIRO E FRACIONARIO ### \n"); 
	printf("Valor Original: %f, Inteiro %f, Fracionario %f. \n", man, i, f);
	
}
