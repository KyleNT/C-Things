#include <stdio.h>
#include <locale.h>
int main(){
	
	setlocale(LC_ALL, "Portuguese");
	int a = 17, b= 18;
	
	printf("AND: ");
	if(a > 17 && b > 17){
		printf("Sim (AND)");
	} else{
		printf("Não (AND)");
	}
	
	printf("\nOR: ");
	if(a > 17 || b > 17){
		printf("Sim (OR)");
	} else{
		printf("Não (OR)");
	}
	
	printf("\nNAND: ");
	if(!(a > 17 && b > 17)){
		printf("Sim (AND)");
	} else{
		printf("Não (AND)");
	}
	
	printf("\nNOR: ");
	if(!(a > 17 || b > 17)){
		printf("Sim (NOR)");
	} else{
		printf("Não (NOR)");
	}
	
	printf("\nXOR: ");
	if(a > 17 ^ b > 17){
		printf("Sim (XOR)");
	} else{
		printf("Não (XOR)");
	}
	
	printf("\nXNOR: ");
	if(!(a > 17 ^ b > 17)){
		printf("Sim (XNOR)");
	} else{
		printf("Não (XNOR)");
	}
	return 0;
	
}
