#include <stdio.h>
#include <time.h>
#include <dos.h>

void data_completa(void);
void bdosagem(void);

void main(void)
{
	data_completa();
	bdosagem();
}

void data_completa(void){
	struct tm *ptr;
	time_t lt;
	
	lt = time(NULL);
	ptr = localtime(&lt);
	printf("### DATA COMPLETA ### \n");
	printf("%s \n", asctime(ptr));
}

void bdosagem(void){
	printf("### BDOS ### \n");
	printf("Eu nao sei exatamente o que este comando faz, mas boa sorte ai! \n");
	//while((255 & bdos(1,0,0)) != '\r');
	printf("Bem, o codigo e velho pra kct.");
}
