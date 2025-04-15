#include <stdio.h>

#define ABS(a) (a)<0 ? -(a) : (a)

void main(void)
{
	printf("abs de -1 e 1: %d %d", ABS(-1), ABS(1));
}
