/* Árvore binária */

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

struct tree {
	char info;
	struct tree *left;
	struct tree *right;
};

struct tree *root; //Primeiro nó da árvore
struct tree *stree (struct tree *root, struct tree *r, char info);
void print_tree(struct tree *root, int l);

void main(void) {
	char s[80];
	setlocale(LC_ALL, "French");
	root = NULL; //Inicializa a raiz
	do {
		printf("Entrez une lettre: ");
		gets(s);
		if(!root) root = stree(root, root, *s);
		else stree(root, root, *s);
	} while(*s);
	print_tree(root, NULL);
}

struct tree *stree (
	struct tree *root,
	struct tree *r,
	char info)
{
	if(!r) {
		r = (struct tree *) malloc(sizeof(struct tree));
		if(!r) {
			printf("Aucune mémoire allouée \n");
			exit(0);
		}
		r->left = NULL;
		r->right = NULL;
		r->info = info;
		if(!root) return r; //Primeira entrada
		if(info<root->info) root->left = r;
		else root->right = r;
		return r;
	}
	
	if(info<r->info) stree(r, r->left, info);
	else
		stree(r, r->right, info);
}

void print_tree(struct tree *r, int l) {
	int i;
	
	if(!r) return;
	
	print_tree(r->right, l+1);
	for(i=0; i<l; ++i) printf(" ");
	printf("%c\n", r->info);
	print_tree(r->left, l+1);
}
