#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

int main(){
	
	
	//Formula Blondel
	//2E+P =+/- 64 cm
	//Largura (28-32) cm
	//Espelho (16-18)cm
		double altura, espelho, quantidade, piso, degrau, largura, patamar;		

		printf("------- Disclaimer -------\n");
		printf("Tread width must be between 28cm to 32cm \n");
		printf("Riser must be between 16 cm and 18 cm \n\n");
		
		printf("Digite a altura: ");
		scanf("%lf", &altura);
		
		printf("Digite o espelho (cm): ");
		scanf("%lf", &espelho);
		
		quantidade = floor(altura/espelho);
		degrau = quantidade - 1;
		piso = 64 - (espelho*2);
		
		double patamar_result, patamar2;
		patamar_result = floor(altura / 290);
		patamar = patamar_result*80;
		patamar2 = patamar/80;
		
		largura = (piso * degrau)+patamar;
		
		printf("\n------- CALCULATE TREAD (_) AND RISER (|)------- \n");
		printf("Altura: \t\t %.2lf m \n", (altura/100));
		printf("Espelho (Riser): \t %.0lf cm \n", espelho);
		printf("Quantidade: \t\t %.0lf \n", quantidade);
		printf("Piso (Tread): \t\t %.0lf cm\n", piso);
		printf("Degrau: \t\t %.0lf \n", degrau);
		printf("Largura: \t\t %.2lf m\n", (largura/100));		
		printf("Patamar(es): \t\t %.0lf \n", patamar2);
		printf("------------------------------------------\n");
		
	
	return 0;
}
