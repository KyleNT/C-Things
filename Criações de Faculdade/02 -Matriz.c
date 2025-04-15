#include <stdio.h>

int main(){
	int tabla[4][4];
	int i,j;
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			tabla[i][j] = i * j;
			printf("%d ", tabla[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
