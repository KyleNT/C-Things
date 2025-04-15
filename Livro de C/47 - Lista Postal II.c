#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct list_type {
	char name[100];
	char street[100];
	char city[100];
	char state[100];
	char zip[100];
} list[SIZE];

int menu(void);
void init_list(void), enter(void);
void display(void), save(void);
void load(void);

void main(void){
	char choice;
	init_list();
	
	for(;;){
		choice = menu();
		switch(choice) {
			case 'i': enter();
			break;
			case 'v': display();
			break;
			case 's': save();
			break;
			case 'c': load();
			break;
			case 't': exit(0);
		}
	}
}

void init_list(void)
{
	register int t;
	for(t=0; t<SIZE; t++) *list[t].name = '\0';
}

void enter(void)
{
	register int i;
	
	for(i=0; i<SIZE; i++)
		if(!*list[i].name) break;
		
	if(i==SIZE){
		printf("Lista cheia\n");
		return;
	}
	
	printf("Nome: ");
	gets(list[i].name);
	
	printf("Rua: ");
	gets(list[i].street);
	
	printf("Cidade: ");
	gets(list[i].city);
	
	printf("Estado: ");
	gets(list[i].state);
	
	printf("CEP: ");
	gets(list[i].zip);
}

void display(void)
{
	register int t;
	
	for(t=0; t<SIZE; t++){
		if(*list[t].name){
			printf("%s\n", list[t].name);
			printf("%s\n", list[t].street);
			printf("%s\n", list[t].city);
			printf("%s\n", list[t].state);
			printf("%s\n\n", list[t].zip);
		}
	}
}

void save(void)
{
	FILE *fp;
	register int i;
	
	if((fp=fopen("katyusha.bin", "wb"))==NULL) {
		printf("O arquivo nao pode ser aberto. \n");
		return;
	}
	
	for(i=0; i<SIZE; i++)
		if(*list[i].name)
		
			if(fwrite(&list[i], sizeof(struct list_type), 1, fp) != 1)
				printf("Erro na escrita no arquivo. \n");
	fclose(fp);
}

void load(void)
{
	FILE *fp;
	register int i;
	
	if((fp=fopen("katyusha.bin", "rb"))==NULL){
		printf("O arquivo nao pode ser aberto. \n");
		return;
	}
	
	init_list();
	for(i=0; i<SIZE; i++)
		if(fread(&list[i], sizeof(struct list_type), 1, fp) != 1) {
			if(feof(fp)) break;
			printf("Erro de leitura no arquivo. \n");
		}
		
	fclose(fp);
}

menu(void){
	char s[80];
	do{
		printf("(I)nserir \n");
		printf("(V)isualizar \n");
		printf("(C)arregar \n");
		printf("(S)alvar \n");
		printf("(T)erminar \n");
		gets(s);
	} while(!strchr("ivcst", tolower(*s)));
	return tolower(*s);
}
