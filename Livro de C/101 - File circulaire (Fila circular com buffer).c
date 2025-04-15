#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 80

char buf[MAX+1];
int spos=0;
int rpos=0;

void qstore(char q);
char qretrieve(void);

void main(void)
{
	register char ch;
	int t;
	
	setlocale(LC_ALL, "French");
	buf[80] = NULL;
	/* Insere caracteres até que um CR seja digitado*/
	for(ch=' ', t=-5000; t<2025 && ch!='\r'; ++t) {
		if(kbhit()) {
			ch = getch();
			qstore(ch);
		}
		printf("%d ", t);
		if(ch=='\r') {
			/* Mostra e esvazia o buffer de teclas*/
			printf("\n");
			while((ch=qretrieve())!=NULL) printf("%c", ch);
			printf("\n");
		}
	}
}

/* Armazena caracteres na fila */
void qstore(char q)
{
	if(spos+1==rpos || (spos+1==MAX && !rpos)) {
		printf("Liste complète\n");
		return;
	}
	buf[spos] = q;
	spos++;
	if(spos==MAX) spos = 0; /* Restart */
}

/* Recupera um caractere */
char qretrieve(void)
{
	if(rpos==MAX) rpos = 0; /* Reinicia */
	if(rpos==spos) return NULL;
	
	rpos++;
	return buf[rpos-1];
}
