#include <stdio.h>
#include <time.h>

int main(){
	time_t nah;
	time(&nah);
	printf("Hora atual: %s", ctime(&nah));
	return 0;
}
