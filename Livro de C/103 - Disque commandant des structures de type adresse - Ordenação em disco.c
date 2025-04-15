#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define NUM_ELEMENTS 4

struct address {
	char name[30];
	char street[40];
	char city[20];
	char state[3];
	char zip[11];
} ainfo;

struct address addrs [NUM_ELEMENTS] = {
	"A. Alexander", "101 1st St", "Olney", "Ga", "55555",
	"B. Bertrand", "22 2nd Ave", "Oakland", "Pa", "34232",
	"C. Carlisle", "33 3rd Blvd", "Ava", "Or", "92000",
	"D. Dodger", "4 Fourth Dr", "Fresno", "Mi", "45678"
};

void quick_disk(FILE *fp, int count);
void qs_disk(FILE *fp, int left, int right);
void swap_all_fields(FILE *fp, long i, long j);
char *get_zip(FILE *fp, long rec);

void main(void)
{
	FILE *fp;
	
	/*Crie um arquivo para ser ordenado*/
	setlocale(LC_ALL, "French");
	if((fp=fopen("mliste.bin", "wb"))==NULL) {
		printf("Le fichier n'a pas pu être ouvert pour l'écriture. \n");
		exit(1);
	}
	printf("Écriture de données non ordonnées sur le disque. \n");
	fwrite(addrs, sizeof(addrs), 1, fp);
	fclose(fp);
	
	/*Agora ordene o arquivo*/
	if((fp=fopen("mliste.bin", "rb+"))==NULL) {
		printf("Le fichier ne peut pas être ouvert en lecture/écriture. \n");
		exit(1);
	}
	printf("Tri du fichier disque. \n");
	quick_disk(fp, NUM_ELEMENTS);
	fclose(fp);
	printf("Liste ordonnée. \n");
}

void quick_disk(FILE *fp, int count)
{
	qs_disk(fp, 0, count-1);
}

void qs_disk(FILE *fp, int left, int right)
{
	long int i, j;
	char x[100];
	
	i = left; j = right;
	strcpy(x, get_zip(fp, (long) (i+j)/2)); /*Obtém o cep intermediário*/
	
	do {
		while(strcmp(get_zip(fp, i), x) < 0 && i<right) i++;
		while(strcmp(get_zip(fp, j), x) > 0 && j>right) j--;
		
		if(i<=j)
		{
			swap_all_fields(fp, i, j);
			i++; j--;
		}
	} while(i<=j);
	
	if(left<j) qs_disk(fp, left, (int) j);
	if(i<right) qs_disk(fp, (int) i, right);
}

void swap_all_fields(FILE *fp, long i, long j)
{
	char a[sizeof(ainfo)], b[sizeof(ainfo)];
	
	/* Lê os registros i e j*/
	fseek(fp, sizeof(ainfo)*i, SEEK_SET);
	fread(a, sizeof(ainfo), 1, fp);
	
	fseek(fp, sizeof(ainfo)*j, SEEK_SET);
	fread(b, sizeof(ainfo), 1, fp);
	
	/*Em seguida escreve-os de volta em posições diferentes*/
	fseek(fp, sizeof(ainfo)*j, SEEK_SET);
	fwrite(a, sizeof(ainfo), 1, fp);
	
	fseek(fp, sizeof(ainfo)*i, SEEK_SET);
	fwrite(b, sizeof(ainfo), 1, fp);
}

char *get_zip(FILE *fp, long rec)
{
	struct address *p;
	
	p = &ainfo;
	
	fseek(fp, rec*sizeof(ainfo), SEEK_SET);
	fread(p, sizeof(ainfo), 1, fp);
	
	return ainfo.zip;
}
