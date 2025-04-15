#include <stdio.h>
#include <locale.h>

void setarlocal(void);
void formatohora(void);
void tempo(void);

void main(void)
{
	setarlocal();
	formatohora();
	tempo();
}

void setarlocal(void){
	printf("### SETAR LOCAL ### \n");
	printf("%s \n", setlocale(LC_ALL, ""));
}

void formatohora(void){
	char str[100];
	struct tm *ltime;
	time_t lt;
	
	lt = time(NULL);
	ltime = localtime(&lt);
	printf("### FORMATAR HORA ### \n");
	strftime(str, 100, "Agora sao %H %p",ltime);
	printf("%s \n", str);
}

void tempo(void){
	struct tm *ptr;
	time_t lt;
	
	lt = time(NULL);
	ptr = localtime(&lt);
	
	printf("### TEMPO ### \n");
	printf("%s \n", asctime(ptr));
}
