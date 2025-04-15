#include <stdio.h>
#include <math.h>


int main(){

	double ton_nave = 1000, ton_comb = 2000, tempo=60, v_ejetada = 3000, alfa, modf, v;	
	
		alfa = ton_comb*1000/tempo;
		modf = alfa*v_ejetada - ton_nave*1000*10;
		v = v_ejetada * log((ton_nave*1000+ton_comb*1000)/(ton_nave*1000))-10*tempo;
			
		printf("\n-------- ERGEBNISSE -------- \n");
		printf("\nTreibstoff: \t\t\t\t\t\t %.0lf t;", ton_comb);
		printf("\nKirchenschiff: \t\t\t\t\t\t %.0lf t;", ton_nave);
		printf("\nZeit: \t\t\t\t\t\t\t %0.lf s;", tempo);
		printf("\nGeschwindigkeit des ausgestossenen Gases: \t\t %.0lf m/s\n", v_ejetada);
		
		if(alfa < 1000){
			printf("Durchschnittliche Rate des ausgestossenen Kraftstoffs: \t %.3lf kg/s \n", alfa);		
		} else{
			double tempAB = alfa/1e3;
			printf("Durchschnittliche Rate des ausgestossenen Kraftstoffs: \t %.3lf t/s \n", tempAB);
		}
		
		if(modf < 1000 ){
			double tempA = modf;
			printf("Modul F: \t\t\t\t\t\t %.3lf N \n", tempA);
		} else if (modf > 1e3 && modf < 1e6){
			double tempB = modf/1e3;
			printf("Modul F: \t\t\t\t\t\t %.3lf kN \n", tempB);
		} else if (modf > 1e6 && modf < 1e9){
			double tempC = modf/1e6;
			printf("Modul F: \t\t\t\t\t\t %.3lf MN \n", tempC);
		}
		
		printf("Geschwindigkeit: \t\t\t\t\t %.3lf m/s \n", v);
		printf("\n-------- ENDE ERGEBNISSE -------- \n");
		
	
	return 0;
}
