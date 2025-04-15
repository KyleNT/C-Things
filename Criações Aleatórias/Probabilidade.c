#include <stdio.h>

int main(){
	
	double acprob, erprob;
	double acertos, erros, poracertos, porerros;
	int count = 0;	
	
	acprob = 5.0/8;
	erprob = 3.0/8;
	
	do{
		count++;
		
		double temp = count;
		acertos = acprob * temp;
		erros = erprob * temp;
		
		poracertos = (int)(acertos * 100) % 100;


		if(poracertos > 0){
			porerros = 100 - poracertos; 	
		} else{
			porerros = 0;
			poracertos = 100;
		}

		
		//if(porerros == 100){
			printf("%d. Tentativa: %.3lf de acertos, %.3lf de erros, Tecido Extra: ", count, acertos, erros);
			printf("Acertos: %.0lf por cento, Erros: %.0lf por cento; \n", poracertos, porerros);
		//} else
		//{
		//	continue;
		//}

		
	} while (count < 16);
	
	return 0;
}
