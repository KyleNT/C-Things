#include <stdio.h>

char* xor(int a, int b);
char* xnor(int a, int b);

void main(void){
	printf("A\tB\tXOR \n");
	printf("1\t0\t%s \n", xor(1, 0));
	printf("1\t1\t%s \n", xor(1, 1));
	printf("0\t1\t%s \n", xor(0, 1));
	printf("0\t0\t%s \n", xor(0, 0));
	
	printf("A\tB\tXNOR  \n");
	printf("1\t0\t%s \n", xnor(1, 0));
	printf("1\t1\t%s \n", xnor(1, 1));
	printf("0\t1\t%s \n", xnor(0, 1));
	printf("0\t0\t%s \n", xnor(0, 0));
}

char* xor (int a, int b){
	if (((a || b) && !(a && b)) == 1){
		return "TRUE";
	} else {
		return "FALSE";
	};
}

char* xnor (int a, int b){
	if ((a == b) == 1){
		return "TRUE";
	} else {
		return "FALSE";
	};
}
