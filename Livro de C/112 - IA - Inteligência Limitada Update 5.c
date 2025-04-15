//Pesquisa de profundidade primeiro
#include <stdio.h>
#include <string.h>

#define MAX 100

//Estrutura do banco de dados sobre os voos
struct FL {
	char from[20]; //de
	char to[20]; //para
	int distance; 
	char skip; // usado para retorno
};

struct FL flight[MAX]; //Matriz de estruturas do bd

int f_pos= 0; //Numero de entradas do bd dos voos
int find_pos = 0; //Indice de pesquisa no bd dos voos
int tos=0; //Topo da pilha
int stos = 0; //Topo da pilha de solução
struct stack {
	char from[20];
	char to[20];
	int dist;
};
struct stack bt_stack[MAX]; //Pilha de retorno
struct stack solution[MAX]; //Guarda soluções temporárias

void setup(void);
int route(char *to);
void assert_flight(char *from, char *to, int dist);
void push(char *from, char *to, int dist);
void pop(char *from, char *to, int *dist);
void isflight(char *from, char *to);
void spush(char *from, char *to, int dist);
int find(char *from, char *anywhere);
int match(char *from, char *to);

void main(void) {
	char from[20], to[20];
	int t,d;
	
	setup();
	
	printf("De? ");
	fgets(from, sizeof(from), stdin);
    from[strcspn(from, "\n")] = 0;
	printf("Para? ");
	fgets(to, sizeof(to), stdin);
    to[strcspn(to, "\n")] = 0;
    
    do{
		isflight(from, to);
		d = route(to);
		tos = 0; //Reinicializa a pilha de retorno
	} while(d!=0); //Enquanto estiver encontrando soluções

	t = 0;
	printf("A solucao otima e: \n");
	while(t<stos) {
		printf("%s para ", solution[t].from);
		d += solution[t].dist;
		t++;
	}
	printf("%s\n", to);
	printf("A distancia e %d. \n", d);
}

//Incializa o banco de dados de voos
void setup(void){
	assert_flight("New York", "Chicago", 1000);
	assert_flight("Chicago", "Denver", 1000);
	assert_flight("New York", "Toronto", 800);
	assert_flight("New York", "Denver", 1900);
	assert_flight("Toronto", "Calgary", 1500);
	assert_flight("Toronto", "Los Angeles", 1800);
	assert_flight("Toronto", "Chicago", 500);
	assert_flight("Denver", "Urbana", 1000);
	assert_flight("Denver", "Houston", 1500);
	assert_flight("Houston", "Los Angeles", 1500);
	assert_flight("Denver", "Los Angeles", 1000);
}

//Coloca os fatos no banco de dados
void assert_flight(char *from, char *to, int dist)
{
	if(f_pos<MAX) {
		strcpy(flight[f_pos].from, from);
		strcpy(flight[f_pos].to, to);
		flight[f_pos].distance=dist;
		flight[f_pos].skip = 0;
		f_pos++;
	}
	else printf("Banco de dados de voos cheio. \n");
}

//Mostra a rota e a distância total
route(char *to)
{
	int dist, t;
	static int old_dist = 32000;
	if(!tos) return 0; //Feito
	dist = 0;
	t = 0;
	//printf("TOS antes do Loop: %d \n", tos);
	while(t<tos) {
		dist += bt_stack[t].dist;
		t++;
	}
	//Se menor, então ache nova solução
	if(dist<old_dist && dist) {
		t = 0;
		old_dist = dist;
		stos = 0; //Limpa a rota antiga da pilha de posição
		while(t<tos) {
			spush(bt_stack[t].from, bt_stack[t].to, bt_stack[t].dist);
			t++;
		}
	}
	return dist;
}

//Se ha o voo entre from e to, então devolve a distancia do voo, caso contrario, devolve 0
match(char *from, char *to)
{
	register int t;
	
	for(t=f_pos-1; t>-1; t--)
		if(!strcmp(flight[t].from, from) && !strcmp(flight[t].to, to)) return flight[t].distance;
	
	return 0; //Não encontrado
}

//Dadofrom, encontre anywhere
find(char *from, char *anywhere)
{
	find_pos = 0;
	while(find_pos<f_pos) {
		if(!strcmp(flight[find_pos].from, from) && !flight[find_pos].skip) {
			strcpy(anywhere, flight[find_pos].to);
			flight[find_pos].skip = 1; //Torna ativo
			return flight[find_pos].distance;
		}
		find_pos++;
	}
	return 0;
}

void isflight(char *from, char *to)
{
	int d, dist;
	char anywhere[20];
	
	//Vê se está no destino
	if(d=match(from, to)) {
		push(from, to, d);
		//printf("Match! \n");
		return;
	}
	
	//Tenta outro comando
	if(dist=find(from, anywhere)) {
		push(from, to, dist);
		//printf("Find! \n");
		isflight(anywhere, to);
	}
	
	else if(tos>0) {
		//Retorna
		pop(from, to, &dist);
		//printf("Pop! \n");
		isflight(from, to);
	}
}

//Rotinas de pilha
void push(char *from, char *to, int dist) {
	if(tos<MAX) {
		strcpy(bt_stack[tos].from, from);
		strcpy(bt_stack[tos].to, to);
		bt_stack[tos].dist=dist;
		//printf("Push: %d \n", bt_stack[tos].dist);
		tos++;
	}
	else printf("Pilha cheia. \n");
}

void pop(char *from, char *to, int *dist) {
	if(tos>0) {
		tos--;
		strcpy(from, bt_stack[tos].from);
		strcpy(to, bt_stack[tos].to);
		*dist=bt_stack[tos].dist;
		//printf("Pop: %d \n", bt_stack[tos].dist);
	}
	else printf("Pilha vazia. \n");
}

void spush(char *from, char *to, int dist) {
	if(stos<MAX) {
		strcpy(solution[stos].from, from);
		strcpy(solution[stos].to, to);
		solution[stos].dist = dist;
		stos++;
	}
	else printf("Pilha de menor distancia cheia. \n");
}
