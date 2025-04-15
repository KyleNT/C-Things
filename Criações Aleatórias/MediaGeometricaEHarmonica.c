#include <stdio.h>
#include <math.h>

int main(){
	
	int diaspora = 0;
	
	printf("Selecione 1 para Media Geometrica, 2 para Media Harmonica: \n");
	scanf("%d", &diaspora);
	
	switch(diaspora){
		case 1:
			//Média Geométrica
			printf("\nBem vindo a calculadora de Media Geometrica \n");
			
			int rest = 0;
			double ricoop = 1.0, naipes, lady, diana;
			
			do{
				printf("Digite o %d numero: ", (rest+1));
				scanf("%lf", &naipes);
				
		        if (naipes != 0){
		            ricoop *= naipes;
		        } else {
		            ricoop *= 1;
		        }
		
		        if (naipes != 0) rest++;
		            else break;		
			} while (naipes != 0);
			
			lady = 1.0/rest;
		    diana = pow(ricoop, lady);
		
		    printf("\n Resultado: %lf", diana);
		break;
		
		case 2:
			//Média Harmônica
			printf("\nBem vindo a calculadora de Media Harmoônica \n");
			
			int sakamotum = 0;
			double cirno = 0, reimu;
			double koakuma;
			
			do{
				printf("Digite o %d numero: ", (sakamotum+1));
				scanf("%lf", &koakuma);
				
	            if (koakuma != 0){
	                cirno += 1.0/koakuma;
	            } else {
	                cirno += 0;
	            }
	
	            if (koakuma != 0) sakamotum++;
	            else break;
	            
			} while(koakuma != 0);
			
			reimu = sakamotum/cirno;
			
			printf("Resultado: %lf", reimu);
		break;
		
		default:
			printf("Nada selecionado!");
		break;
	}
	
	return 0;
}
