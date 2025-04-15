#include <stdio.h>
#include <time.h>
#include <locale.h>

void utc(void);
void decimal(void);
void horaloc(void);
void fazer_hora(void);

void main(void){
	utc();
	decimal();
	horaloc();
	fazer_hora();
}

void utc(void){
	struct tm *local, *gm;
	time_t t;
	
	t = time(NULL);
	local = localtime(&t);
	printf("### UTC ### \n");
	printf("Hora local e a data: %s\n", asctime(local));
	gm = gmtime(&t);
	printf("Hora universal e data: %s \n", asctime(gm));
}

void decimal(void){
	struct lconv lc;
	lc = *localeconv();
	printf("### DECIMAL ### \n");
	printf("Simbolo decimal e: %s\n", lc.decimal_point);
}

void horaloc(void){
	struct tm *local;
	time_t t;
	t = time(NULL);
	local = localtime(&t);
	printf("### HORA LOCAL, DATA E HORA UTC ### \n");
	printf("Hora local e a data: %s\n", asctime(local));
	local = gmtime(&t);
	printf("Hora de UTC e data: %s\n", asctime(local));
}

void fazer_hora(void){
	struct tm t;
	time_t t_of_day;
	
	t.tm_year = 1999-1900;
	t.tm_mon = 0;
	t.tm_mday = 3;
	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 1;
	t.tm_isdst = 0;
	
	t_of_day = mktime(&t);
	printf("### HORA CRIADA ### \n");
	printf("%s \n", ctime(&t_of_day));
}
