/* Programa cde lista postal que ilustra o uso e a manutenção de listas duplamente encadeadas*/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

struct address {
	char name[50];
	char street[50];
	char city[50];
	char state[50];
	char zip[11];
	struct address *next; //Ponteiro para a proxima entrada
	struct address *prior; //ponteiro para o registro anterior
} list_entry;

struct address *start; //Ponteiro para a primeira entrada da lista
struct address *last; //Ponteiro para a ultima entrada
struct address *find(char *);

void enter(void), search(void), save(void);
void load(void), list(void);
void deleter(struct address **, struct address **);
void dls_store(struct address *i, struct address **start, struct address **last);
void inputs(char *, char *, int), display(struct address *);
int menu_select(void);

void main(void) {
	setlocale(LC_ALL, "French");
	printf("___________                           .__      __________              __   \n");
printf("\\_   _____/______  ____   ____   ____ |  |__   \\______   \\____  ______/  |_ \n");
printf(" |    __) \\_  __ \\/ __ \\ /    \\_/ ___\\|  |  \\   |     ___/  _ \\/  ___|   __\\ \n");
printf(" |     \\   |  | \\|  ___/|   |  \\  \\___|   Y  \\  |    |  (  <_> )___ \\ |  |  \n");
printf(" \\___  /   |__|   \\___  >___|  /\\___  >___|  /  |____|   \\____/____  >|__|  \n");
printf("     \\/               \\/     \\/     \\/     \\/                      \\/     \n");
	start = last = NULL; //inicia os ponteiros de inicio e fim
	for(;;) {
		switch(menu_select()) {
			case 1: enter();
			break;
			case 2: deleter(&start, &last);
			break;
			case 3: list();
			break;
			case 4: search(); //Encontra uma rua
			break;
			case 5: save(); //Grava a lista no disco
			break;
			case 6: load(); //Lê do disco
			break;
			case 7: exit(0);
			break;
			default: printf("Veuillez saisir les chiffres de 1 à 7.");
			break;
		}
	}
}

menu_select(void) { //Seleciona uma operação
	char s[80];
	int c;
	
	printf("1. Entrez un nom \n");
	printf("2. Supprimer un nom \n");
	printf("3. Lister le fichier \n");
	printf("4. À rechercher \n");
	printf("5. Enregistrer le fichier \n");
	printf("6. Télécharger le fichier \n");
	printf("7. Sortir \n");
	do {
		printf("\nEntrez votre choix: ");
		gets(s);
		c = atoi(s);
	} while(c < 0 || c > 7);
	return c;
}

void enter(void) { //Insere nomes e endereços
	struct address *info;

	for(;;) {
		info = (struct address *)malloc(sizeof(list_entry));
		if(!info) {
			printf("\nAucune allocation de mémoire\n");
			return;
		}
		inputs("Entrez le nom: ", info->name, 50);
		if(!info->name[0]) break; //Não faz a inserção
		inputs("Entrez dans la rue: ", info->street, 50);
		inputs("Entrez la ville: ", info->city, 50);
		inputs("Entrez l'état: ", info->state, 50);
		inputs("Entrez le code postal: ", info->zip, 10);
		dls_store(info, &start, &last);
	} //Laço de entrada
} /* Essa função acima lê uma string de comprimento máximo count e evita que a string seja ultrapossada. Ela também apresenta uma mensagem de aviso*/

void inputs(char *prompt, char *s, int count){
	char p[255];
	
	do {
		printf(prompt);
		gets(p);
		if(strlen(p)>count) printf("\nTrès long.\n");
	} while(strlen(p)>count);
	strcpy(s, p);
}

/*Cria uma lista duplamente encadeada ordenada. */
void dls_store (
	struct address *i, /* novo elemento */
	struct address **start, /* primeiro elemento da lista */
	struct address **last /*último elemento da lista*/
)
{
	struct address *old, *p;
	
	if(*last==NULL) {
		i->next = NULL;
		i->prior = NULL;
		*last = i;
		*start = i;
		return;
	}
	p = *start; /*Começa o topo da lista*/
	old = NULL;
	while(p) {
		if(strcmp(p->name, i->name)<0) {
			old = p;
			p = p->next;
		}
		else {
			if(p->prior) {
				p->prior->next = i;
				i->next = p;
				i->prior = p->prior;
				p->prior = i;
				return;
			}
			i->next = p; /* Novo primeiro elemento */
			i->prior = NULL;
			p->prior = i;
			*start = i;
			return;
		}
	}
	old->next = i; /* Coloca no final*/
	i->next = NULL;
	i->prior = old;
	*last = i;
}

/*Remove um elemento da lista*/
void deleter(struct address **start, struct address **last) {
	struct address *info, *find();
	char s[80];
	
	printf("Entrez le nom à supprimer: ", s, 50);
	info = find(s);
	if(info) {
		if(*start==info){
			*start = info->next;
			if(*start) (*start)->prior = NULL;
			else *last = NULL;
		}
		else {
			info->prior->next = info->next;
			if(info!=*last)
				info->next->prior = info->prior;
			else
				*last = info->prior;
		}
		free(info);
	}
}

/* Encontra um endereço */
struct address *find(char *name) {
	struct address *info;
	info = start;
	while(info) {
		if(!strcmp(name, info->name)) return info;
		info = info->next; /* Obtém novo endereço */
	}
	printf("Nom non trouvé. \n");
	return NULL;
}

/*Mostra a lista completa*/
void list(void)
{
	struct address *info;
	
	info = start;
	while(info) {
		display(info);
		info = info->next;
	}
	printf("\n\n");
}

/*Esta função imprime os campos de cada tela*/
void display(struct address *info)
{
	printf("%s\n", info->name);
	printf("%s\n", info->street);
	printf("%s\n", info->city);
	printf("%s\n", info->state);
	printf("%s\n", info->zip);
	printf("\n\n");
}

/* Procura por um nome na lista. */
void search(void) {
	char name[40];
	struct address *info, *find();
	
	printf("Entrez le nom à rechercher: ");
	gets(name);
	info = find(name);
	if(!info) printf("Non trouvé\n");
	else display(info);
}

/* Salva o arquivo em disco */
void save(void) {
	struct address *info;
	FILE *fp;
	
	fp = fopen("mlist_lp.bin", "wb");
	if(!fp) {
		printf("Le fichier n'a pas pu être ouvert.\n");
		exit(1);
	}
	printf("\nEnregistrer le fichier\n");
	info = start;
	while(info){
		fwrite(info, sizeof(struct address), 1, fp);
		info = info->next; /*Obtém o próximo endereço*/
	}
	fclose(fp);
}

/* Carrega o arquivo de endereço */
void load()
{
	struct address *info;
	FILE *fp;
	
	fp = fopen("mlist_lp.bin", "rb");
	if(!fp) {
		printf("Le fichier n'a pas pu être ouvert.\n");
		exit(1);
	}
	/* Libera qualquer memória previamente alocada*/
	while(start) {
		info = start->next;
		free(info);
		start = info;
	}
	/* Reinicializa os ponteiros de início e fim*/
	start = last = NULL;
	printf("\nChargement du fichier...\n");
	while(!eof(fp)) {
		info = (struct address *) malloc(sizeof(struct address));
		if(!info) {
			printf("\nAucune allocation de mémoire\n");
			return;
		}
		if(1!=fread(info, sizeof(struct address), 1, fp)) break;
		dls_store(info, &start, &last);
	}
	fclose(fp);
}
