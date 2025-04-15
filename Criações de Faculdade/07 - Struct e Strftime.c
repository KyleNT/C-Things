#include <stdio.h>
#include <time.h>

int main(){
	time_t nah;
	struct tm *infojob;
	char bufa[80];
	
	time(&nah);
	infojob = localtime(&nah);
	strftime(bufa, 80, "Data e hora: %d/%m/%Y %H:%M:%S", infojob);
	printf("%s \n", bufa);
	return 0;
}
