#include <stdio.h>

void incrStatic(){
	
	static int cont = 1;
	cont++;
	
	printf("Contador Estatico: %d\n", cont);
}

void incr(){
	
	int conta = 0;
	conta++;
	
	printf("Contador Nao Estatico: %d\n", conta);
}

int main(){
	
	printf("Xal");
	
	incrStatic();
	incrStatic();
	incr();
	incr();
	
	return 0;
}
