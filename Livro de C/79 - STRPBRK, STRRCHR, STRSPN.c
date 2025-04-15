#include <stdio.h>
#include <string.h>

void string_pbrk(void);
void string_rchr(void);
void string_spn(void);

void main(void)
{
	string_pbrk();
	string_rchr();
	string_spn();
}

void string_pbrk(void){
	char *p;
	
	p = strpbrk("isto e um teste", "ebkj");
	printf("%s \n", p);
}

void string_rchr(void){
	char *p;
	
	p = strrchr("isto e um teste", 'o');
	printf("%s \n", p);
}

void string_spn(void){
	int len;
	
	len = strspn("isto e um teste", "otsi ");
	printf("%d \n", len);
}
