#include <stdio.h>

int main(){
	int i = 0;
	
	while(i <= 10){
		//imprime i e pula uma linha
		printf("%d \n", i);
		
		//aumenta em 1 o valor do i atual
		i = i+1;
		//se i <= 10 for verdade, execute o loop, até for falso e sair do loop.
	}
	return 0;
}
