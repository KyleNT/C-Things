#include <stdio.h>
#include <string.h>

#define SIZE 80

void main(void)
{
	char buf1[SIZE], buf2[SIZE];
	
	strcpy(buf1, "1984 American Election");
	memcpy(buf2, buf1, SIZE);
	printf(buf2);
}
