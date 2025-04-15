#include <stdio.h>

void main(void){
	printf("%x %#x\n", 10, 10); //Hex e 0xHex
	printf("%o %#o\n", 10, 10); //Oct e 0Oct
	printf("%*.*f",10,4,1234.34); //Campo 10, precisão 4, float
}
