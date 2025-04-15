#include <stdio.h>

#define LG 11

void main(void)
{
	int tristepartida = 144;
	int _1964[LG];
	char *LG_1964[] = {
		"A Triste Partida",
		"Toque do Rancho",
		"Cacimba Nova",
		"Marimbondo",
		"Ave Maria Sertaneja",
		"Numa Sala de Reboco",
		"Viva o Arigo",
		"Cantiga de Vem Vem",
		"Cocotah",
		"Forro do Ze do Baile",
		"Lembranca de Primavera"
	};
	
	printf("%-20s \n", "Teste de 12");
	
	printf("%10.3f \n", 12.234567);
	
	printf("1964 - Luiz Gonzaga (HEX)\n");
	
	for(int i=0; i<LG; i++)
	{
		_1964[i] = 144+i;
		printf("%#X.%s\n", _1964[i], LG_1964[i]);
	}
	
	printf("\n1964 - Luiz Gonzaga (OCT)\n");
	
	for(int i=0; i<LG; i++)
	{
		_1964[i] = 144+i;
		printf("%#o.%s\n", _1964[i], LG_1964[i]);
	}	
}
