#include <stdio.h>
#include <math.h>

void arco_cosseno(double arg);
void arco_seno(double arg);
void arco_tangente(double arg);
void arco_tangente_x_y(double y, double x);

void main (void){
	double arg, y, x;
	
	arg = -1.0;
	y = arg;
	x = 1.0;
	
	arco_cosseno(arg);
	arco_seno(arg);
	arco_tangente(arg);
	arco_tangente_x_y(y, x);
}

void arco_cosseno(double arg){
	double val = arg;
	printf("### ARCO COSSENO ### \n");
	do{
		printf("Arco cosseno de %f e %f. \n", val, acos(val));
		val += 0.1;
	} while(val<=1.0);
}

void arco_seno(double arg){
	double val = arg;
	printf("\n### ARCO SENO ### \n");
	do{
		printf("Arco seno de %f e %f. \n", val, asin(val));
		val += 0.1;
	} while(val<=1.0);
}

void arco_tangente(double arg){
	double val = arg;
	printf("\n### ARCO TANGENTE ### \n");
	do{
		printf("Arco tangente de %f e %f. \n", val, atan(val));
		val += 0.1;
	} while(val<=1.0);	
}

void arco_tangente_x_y(double y, double x){
	double val = y;
	printf("\n### ARCO TANGENTE DE Y E X ### \n");
	do{
		printf("Arco tangente 2 de %f e %f. \n", val, atan2(val, x));
		val += 0.1;
	} while(val<=1.0);		
}
