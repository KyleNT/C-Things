#include <stdio.h>

int main() {
   char livro[100], autor[100];
   int paginas;

   printf("Digite o nome do livro: ");
   scanf(" %99[^\n]", livro);  // Espa�o para ignorar os espa�os, e 99[\n] para ignorar o 100� Caractere
   printf("Digite o nome do autor: ");
   scanf(" %99[^\n]", autor);  // Espa�o para ignorar os espa�os, e 99[\n] para ignorar o 100� Caractere
   printf("Digite o n�mero de p�ginas: ");
   scanf("%d", &paginas);

   printf("\nVoc� registrou o livro: '%s' de %s, com %d p�ginas.\n", livro, autor, paginas);
   return 0;
}
