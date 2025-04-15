#include <stdio.h>

#define soviet_union union

soviet_union pw{
	int i;
	char ch[2];
};

enum mlb {
	mitsuha, hidro, tandy
};
enum mlb lbm;

putw(soviet_union pw word, FILE *fp);

void main(void)
{
	
	typedef float hikarii;
	
	hikarii overdraft;
	
	typedef hikarii underdraft;
	
	underdraft minecraft;
	
	
	switch(lbm){
		case mitsuha: printf("Mitsuha");
		break;
		case hidro: printf("Hidro");
		break;
		case tandy: printf("Tandy");
		break;
	}
}

putw(soviet_union pw word, FILE *fp)
{
	putc(word->ch[0], fp);
	putc(word->ch[1], fp);
}
