#include <stdio.h>
#include <time.h>
#include <Windows.h>

int main(){
	
	time_t inicio, fim;
	
	time(&inicio);
	printf("Tempo inicial capturado \n");
	
	printf("Esperando por 5 segundos... \n");
	int i;
	for(i = 0; i < 5; i++){
		printf("%d... \n", 5 - i);
		Sleep(1000);
	}
	
	time(&fim);
	printf("Tempo final capturado\n");
	
	double diferenca = difftime(fim, inicio);
	
	printf("A diferenca em segundos e: %.f segundos\n", diferenca);
	
	return 0;
}
