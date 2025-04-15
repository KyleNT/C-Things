#include <stdio.h>

struct a1970 {
	char name[50];
} ana70;

void main (void){
	
	struct {
		int a;
		int b;
	} x, y;
	register int t;
	gets(ana70.name);
	
	x.a = 10;
	y = x;
	
	for(t=0; ana70.name[t]; ++t)
		putchar(ana70.name[t]);
		
	printf("\n%d", y.a);
}
