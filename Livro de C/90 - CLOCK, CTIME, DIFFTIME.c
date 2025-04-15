#include <stdio.h>
#include <time.h>

void elapsed_time(void);
void local_time(void);
void difference_time(void);

void main(void){
	elapsed_time();
	local_time();
	difference_time();
}

void elapsed_time(void){
	printf("### TEMPO TRANSCORRIDO ### \n");
	printf("Tempo transcorrido: %u segs.\n", clock()/CLOCKS_PER_SEC);
}

void local_time(void){
	time_t lt;
	
	lt = time(NULL);
	printf("### HORA LOCAL ### \n");
	printf("%s \n", ctime(&lt));
}

void difference_time(void){
	time_t start, end;
	long unsigned t;
	
	start = time(NULL);
	for(t=0;t<500000; t++);
	end = time(NULL);
	printf("### DIFERENÇA DE TEMPO ### \n");
	printf("O laco usou %f segundos. \n", difftime(end, start));
}
