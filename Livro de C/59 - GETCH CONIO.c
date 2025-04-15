#include <stdio.h>
#include <conio.h>

void main(void)
{
	register char choice;
	
	do{
		printf("1: Digite \n");
		printf("2: Digite \n");
		printf("3: Digite \n");
		printf("4: Digite \n");
		
		printf("\nEscolha: \n");
		choice = getch();
	} while(!strchr("1234", choice));
	
	switch(choice)
	{
		case '1':
			printf("Voce escolheu 1!");
		break;
		case '2':
			printf("Voce escolheu 2!");
		break;
		case '3':
			printf("Voce escolheu 3!");
		break;
		case '4':
			printf("Voce escolheu 4!");
		break;
		default:
			printf("Nao selecionado ou invalido!");
		break;
	}
}
