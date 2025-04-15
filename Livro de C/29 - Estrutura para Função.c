#include <stdio.h>

struct struct_type {
	int a, b;
	char ch;
};

void f1 (struct struct_type parmset);

void main(void){
	
	struct struct_type argh;
	
	argh.a = 100;
	f1(argh);
}

void f1(struct struct_type parmset){
	printf("%d", parmset.a);
}
