#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>


int main(void){
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "C.UTF-8");
	
	char jap[] = "カリマセンは８２８ページの本を読んでいます。";

	printf("%s \n", jap);
	
	system("pause");
	
	return 0;
}

