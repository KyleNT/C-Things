
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char caractere;  // Declara uma vari�vel do tipo char para armazenar cada caractere lido

    // Solicita ao usu�rio que digite um texto e informa como sair do programa
    printf("Entre com um texto (Digite ponto (.) para sair do programa): \n");
    
    do {
        caractere = getchar();  // L� um caractere do teclado
        
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
