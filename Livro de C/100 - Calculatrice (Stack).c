#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 100

int *p;
int *tos;
int *bos;

void push(int i);
int pop(void);

void main(void)
{
	
	int a, b;
	char s[80];
	
	p = (int *) malloc(MAX*sizeof(int));
	if(!p) {
		printf("�chec d'allocation\n");
		exit(1);
	}
	tos = p;
	bos = p+MAX-1;
	
	setlocale(LC_ALL, "French");
	printf("Calculatrice � quatre fonctions\n");
	printf("Tapez 's' pour quitter");
	
	do {
		printf(": ");
		gets(s);
		switch(*s){
			case '+':
				a = pop();
				b = pop();
				printf("%d\n", a+b);
				push(a+b);
				break;
			case '-':
				a = pop();
				b = pop();
				printf("%d\n", b-a);
				push(b-a);
				break;
			case '*':
				a = pop();
				b = pop();
				printf("%d\n", b*a);
				push(b*a);
				break;
			case '/':
				a = pop();
				b = pop();
				if(a==0){
					printf("Division par z�ro.\n");
					break;
				}
				printf("%d\n", b/a);
				push(b/a);
				break;
			case '.': /*Topo de pilha*/
				a = pop();
				printf("La valeur actuelle de la pile est: %d", a);
				break;
			default:
				push(atoi(s));
		}
	} while(*s!='s');
	

}

/* P�e um elemento na pilha*/
void push(int i){
	if(p>bos) {
		printf("Pile compl�te\n");
		return;
	}
	*p = i;
	p++;
}

/* Recupera o elemento do topo da pilha */
pop (void) {
	p--;
	if(p<tos) {
		printf("Pile vide\n");
		return 0;
	}
	return *p;
}
