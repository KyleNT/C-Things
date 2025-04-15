//Pesquisa de profundidade primeiro
#include <stdio.h>
#include <string.h>

#define MAX 100

//Estrutura do banco de dados das chaves
struct FL {
	char from[20]; //de
	char to[20]; //para
	char skip; 
};

struct FL keys[MAX]; //Matriz de estruturas do bd

int f_pos= 0; //Numero de comodos na casa
int find_pos = 0; //Indice do bd de busca
int tos=0; //Topo da pilha
struct stack {
	char from[20];
	char to[20];
};
struct stack bt_stack[MAX]; //Pilha de retorno

void setup(void), route(void);
void assert_keys(char *from, char *to);
void push(char *from, char *to);
void pop(char *from, char *to);
void iskeys(char *from, char *to);
int find(char *from, char *anywhere);
int match(char *from, char *to);

void main(void) {
	
	setup();
	iskeys("front_door","keys");
	route();

}

//Incializa o banco de dados de voos
void setup(void){
	assert_keys("front_door", "lr");
	assert_keys("lr", "banheiro");
	assert_keys("lr", "hall");
	assert_keys("hall", "bd1");
	assert_keys("hall", "bd2");
	assert_keys("hall", "mb");
	assert_keys("lr", "cozinha");
	assert_keys("cozinha", "keys");

}

//Coloca os fatos no banco de dados
void assert_keys(char *from, char *to)
{
	if(f_pos<MAX) {
		strcpy(keys[f_pos].from, from);
		strcpy(keys[f_pos].to, to);
		keys[f_pos].skip = 0;
		f_pos++;
	}
	else printf("Banco de dados das chaves cheio. \n");
}

//Mostra a rota e a distância total
void route(void)
{
	int dist, t;
	dist = 0;
	t = 0;
	//printf("TOS antes do Loop: %d \n", tos);
	while(t<tos) {
		printf("%s ", bt_stack[t].from);
		t++;
		if(t<tos) printf(" para ");
	}
	//printf("TOS depois do Loop: %d \n", tos);
	printf("\n");
}

//Se ha o voo entre from e to, então devolve a distancia do voo, caso contrario, devolve 0
match(char *from, char *to)
{
	register int t;
	
	for(t=f_pos-1; t>-1; t--)
		if(!strcmp(keys[t].from, from) && !strcmp(keys[t].to, to) && !keys[t].skip) return 1;
	
	return 0; //Não encontrado
}

//Dadofrom, encontre anywhere
find(char *from, char *anywhere)
{
	find_pos = 0;
	while(find_pos<f_pos) {
		if(!strcmp(keys[find_pos].from, from) && !keys[find_pos].skip) {
			strcpy(anywhere, keys[find_pos].to);
			keys[find_pos].skip = 1; //Torna ativo
			return 1;
		}
		find_pos++;
	}
	return 0;
}

void iskeys(char *from, char *to)
{
	char anywhere[20];
	
	//Vê se está no destino
	if(match(from, to)) {
		push(from, to); //Distância
		return;
	}
	
	//Tenta outro comando
	if(find(from, anywhere)) {
		push(from, anywhere);
		iskeys(anywhere, to);
		return;
	}
	
	else if(tos>0) {
		pop(from, anywhere);
		iskeys(from, to);

	}
}

//Rotinas de pilha
void push(char *from, char *to) {
	if(tos<MAX) {
		strcpy(bt_stack[tos].from, from);
		strcpy(bt_stack[tos].to, to);
		//printf("Push: %d \n", bt_stack[tos].dist);
		tos++;
	}
	else printf("Pilha cheia. \n");
}

void pop(char *from, char *to) {
	if(tos>0) {
		tos--;
		strcpy(from, bt_stack[tos].from);
		strcpy(to, bt_stack[tos].to);
		//printf("Pop: %d \n", bt_stack[tos].dist);
	}
	else printf("Pilha vazia. \n");
}
