#include <stdio.h>
#include <locale.h>
int main(){
	
	setlocale(LC_ALL, "Portuguese");
	int a = 17, b= 18;
	
	printf("AND: ");
	if(a > 17 && b > 17){
		printf("Sim (AND)");
	} else{
		printf("N�o (AND)");
	}
	
	printf("\nOR: ");
	if(a > 17 || b > 17){
		printf("Sim (OR)");
	} else{
		printf("N�o (OR)");
	}
	
	printf("\nNAND: ");
	if(!(a > 17 && b > 17)){
		printf("Sim (AND)");
	} else{
		printf("N�o (AND)");
	}
	
	printf("\nNOR: ");
	if(!(a > 17 || b > 17)){
		printf("Sim (NOR)");
	} else{
		printf("N�o (NOR)");
	}
	
	printf("\nXOR: ");
	if(a > 17 ^ b > 17){
		printf("Sim (XOR)");
	} else{
		printf("N�o (XOR)");
	}
	
	printf("\nXNOR: ");
	if(!(a > 17 ^ b > 17)){
		printf("Sim (XNOR)");
	} else{
		printf("N�o (XNOR)");
	}
	return 0;
	
}
