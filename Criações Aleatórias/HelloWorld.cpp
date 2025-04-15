#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef MAX
#define MAX 100
#endif

void rosary(int a, int b){
	int count = 0;
	char paternoster[] = ". Pater Noster, qui es in caelis, sanctificetur nomen tuum. Adveniat regnum tuum. Fiat voluntas tua, sicut in caelo et in terra. Panem nostrum quotidianum da nobis hodie, et dimitte nobis debita nostra sicut et nos dimittimus debitoribus nostris. Et ne nos inducas in tentationem, sed libera nos a malo. Amen.";
	char avemaria[] = ". Ave Maria, gratia plena Dominus tecum Benedicta tu in mulieribus Et benedictus fructus ventris tui, Iesus Sancta Maria, Mater Dei, Ora pro nobis peccatoribus Nunc et in hora mortis nostrae Amen.";
	
	while(count < a){
		int countb = count + 1;

		printf("%d", countb);
		printf("%s\n", paternoster);
		int count2 = 0;
		while(count2 < b){
			int countc = count2 + 1;
			printf("%d.", countb);
			printf("%d", countc);
			printf("%s\n", avemaria);
			count2++;
		}
		count++;
	}
}

int main(){
	system("CHCP 860");
	
	char hello[] ="Hello, World!";
	char separator[] = " --------- ";
	char apresentacao[] = "Apresentacao";
	
	char buffer[MAX];
	
	int x = 1;
	
	strcat(strcpy(buffer,separator),apresentacao);
	printf("%s", buffer);
	printf("%s\n", separator);
	printf("%s\n",hello);
	
	if (x == 1){
		printf("Nao, o mundo nao acabou, o que acabou foi seu PC.\n");
	}
	
	rosary(5,10);
	
	return 0;
}
