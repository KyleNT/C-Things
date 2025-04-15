#include <stdio.h>
#include <time.h>

void delay(int milliseconds);
void delay(int milliseconds)
{
    long pause;
    clock_t now,then;
    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}
int main() {
	//Agulha
	int ponto = 0;
	//Tempo
	int msec = 0, trigger = 1; /* 1ms */
	clock_t before = clock();
	printf("---- Maquina de Costura em C ----\n");
	printf("Selecione quantas agulhas por minuto: ");
	scanf("%d", &ponto);
	printf("\n Carregando os pontos \n");
	int count = 0;
	float ponto_de_parada = 60000/ponto;
	do{
		//Costura
		int loop = count + 1;
		printf("A agulha passou %d vezes; \n", loop);
		delay(ponto_de_parada);
		
		count++;
	} while (count != ponto);
	printf("\n---------- \n");
	printf("\n---------- \n");
	printf("A costura teve %.0f agulhas por segundo \n", 1/(ponto_de_parada/1000));
	printf("A costura realizou %d pontos. \n", ponto);
	//printf("Tempo realizado: %d segundos %d milissegundos (%d iteracoes)\n",  msec/1000, msec%1000, iterations);
	return 0;
}
