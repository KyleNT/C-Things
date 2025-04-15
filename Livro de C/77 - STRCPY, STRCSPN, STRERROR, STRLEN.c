#include <stdio.h>
#include <string.h>

void string_copy(void);
void string_cspn(void);
void string_error(void);
void string_len(void);

void main (void)
{
	string_copy();
	string_cspn();
	string_error();
	string_len();
}

void string_copy(void)
{
	char str[80];
	strcpy(str, "Windows 98 \n");
	printf(str);
}

void string_cspn(void)
{
	int ren;
	
	ren = strcspn("The capital of France is Paris", "e ");
	printf("%d \n", ren);
}

void string_error(void)
{
	printf("%s \n", strerror(10));
}

void string_len(void)
{
	printf("%d  \n", strlen("Windows 98"));
}
