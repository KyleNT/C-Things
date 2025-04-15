#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	float a, b, c, delta, x1, x2;
	printf("Escreva uma equação do segundo grau, obedecendo ax² + bx + c = 0: \n");
	scanf("%f %f %f",&a, &b, &c);
	
	printf("Equação Proposta:");
	printf("%.2fx² + %.2fx + %.2f = 0", a, b, c);
	
	delta = pow(b, 2)-4*a*c;
	
	printf("\nDelta: %.2f\n", delta);
	
	//a = 3 b = 4 c = 1
	x1 = ((-1 * b) + sqrt(delta))/(2*a);
	x2 = ((-1 * b) - sqrt(delta))/(2*a);
	
	printf("X1 = %.2f \n", x1);
	printf("X2 = %.2f \n", x2);
	return 0;
}
