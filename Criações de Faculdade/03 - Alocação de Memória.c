#include <stdio.h>
#include <stdlib.h>

int main(){
	int *numol = (int *) malloc(10 * sizeof(int));
	if (numol == NULL){
		printf("Erro em ao alocar memoria\n");
		return 1;
	}
	int i;
	for (i = 0; i < 10; i++){
		numol[i] = i;
		printf("Numero %d\n", i);
	}
	free(numol);
	return 0;
}
