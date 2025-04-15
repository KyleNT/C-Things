#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <locale.h>

#define MAX 100

char *p[MAX], *qretrieve(void);
int spos = 0;
int rpos = 0;
void enter(void), qstore(char *q), review(void), supprimer(void);

void main(void)
{
	char s[80];
	register int t;
	
	setlocale(LC_ALL, "French");
	for(t=0; t<MAX; ++t) p[t] = NULL; /* Inicia a matriz com nulos */
	for(;;){
		printf("(E)ntrer, (L)ister, (S)upprimer, (Q)uitter: ");
		gets(s);
		*s = toupper(*s);
		switch(*s) {
			case 'E':
				enter();
				break;
			case 'L':
				review();
				break;
			case 'S':
				supprimer();
				break;
			case 'Q':
				exit(0);
		}
	}
}

/* Insere o evento na fila */
void enter(void)
{
	char s[256], *p;
	
	do {
		printf("Entrez l'événement %d : ", spos+1);
		gets(s);
		if(*s==0) break; /* Nenhuma entrada */
		p = malloc(strlen(s)+1);
		if(!p) {
			printf("Sans allocation mémoire.\n");
			return;
		}
		strcpy(p, s);
		if(*s) qstore(p);
	} while (*s);
}

/* Vê o que há na fila*/
void review(void) 
{
	register int t;
	for(t=rpos; t<spos; ++t)
		printf("%d. %s\n", t+1, p[t]);
}

/* Apaga um evento da fila */
void supprimer(void)
{
	char *p;
	
	if((p=qretrieve())==NULL) return;
	printf("%s\n", p);
}

/* Armazena um evento */
void qstore(char *q)
{
	if(spos==MAX) {
		printf("Liste complète\n");
		return;
	}
	p[spos] = q;
	spos++;
}

/* Recupera um evento */
char *qretrieve(void) 
{
	if(rpos==spos) {
		printf("Aucun événement. \n");
		return NULL;
	}
	rpos++;
	return p[rpos-1];
}
