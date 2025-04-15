#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void converge(int line, char *message);

void main (void){
	converge(10, "Quero que tudo va para o inferno, 1965");
}

void converge(int line, char *message){
	int i, j;
	
	for(i = 1, j = strlen(message); i < j; i++, j--){
		gotoxy(i, line); printf("%c", message[i-1]);
		gotoxy(j, line); printf("%c", message[j-1]);
	}
}
