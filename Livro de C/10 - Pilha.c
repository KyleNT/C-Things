#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void push(int i);
int pop(void);

int *tos, *p1, stack[SIZE];

//Pilha: Primeiro a entrar é o último a sair

//Entra-se: 1,2,3,4.
//Na pilha: 4,3,2,1.

void main(void){
	int value;
	
	tos = stack; /* Faz tos conter o topo da pilha */
	p1 = stack; /* Inicializa p1 */
	
	do{
		printf("Digite o valor: ");
		scanf("%d", &value);
		if(value!=0) push(value);
		else printf("valor do topo e %d\n", pop());
	} while(value!=-1);
}

//Aqui é uma soma de ponteiros
//SIZE 5 * 2 bytes do INT = 10
//Não é 0,2,4,6,8,10 para bytes, pois não há -2 bytes.
//Mas sim 2,4,6,8 e 10.
void push(int i){
	p1++;
	if(p1==(tos+SIZE)){
		printf("Estouro da pilha por excesso");
		exit(1);
	}
	*p1 = i;
}


//o p1 e o tos não são valores, mas sim endereços iguais.
pop(void){
	if(p1==tos){
		printf("Estouro da pilha por esvaziamento");
		exit(1);
	}
	p1--;
	return *(p1+1);
}
