#include <conio.h>  // Inclui a biblioteca conio.h que cont�m fun��es espec�ficas do console
#include <stdio.h>  // Inclui a biblioteca padr�o de entrada e sa�da
#include <ctype.h>  // Inclui a biblioteca para fun��es de teste e mapeamento de caracteres

int main(void) {
    char caractere;  // Declara uma vari�vel do tipo char para armazenar cada caractere lido

    // Solicita ao usu�rio que digite um texto e informa como sair do programa
    printf("Entre com um texto (Digite ponto (.) para sair do programa): \n");
    do {
        caractere = getch();  // L� um caractere do teclado sem ecoar na tela
        
        // Verifica se o caractere � uma letra min�scula
        if (islower(caractere)) {
            caractere = toupper(caractere);  // Converte para mai�scula se for min�scula
        }
        else {
            caractere = tolower(caractere);  // Converte para min�scula se n�o for min�scula
        }
        
        putchar(caractere);  // Exibe o caractere convertido no console
    } 
    while (caractere != '.');  // Repete o loop at� que o caractere '.' seja digitado
}
