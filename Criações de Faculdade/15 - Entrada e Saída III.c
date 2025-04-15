#include <stdio.h>

int main() {
   char livro[100], autor[100];
   int paginas;

   printf("Digite o nome do livro: ");
   scanf(" %99[^\n]", livro);  // Espaço para ignorar os espaços, e 99[\n] para ignorar o 100º Caractere
   printf("Digite o nome do autor: ");
   scanf(" %99[^\n]", autor);  // Espaço para ignorar os espaços, e 99[\n] para ignorar o 100º Caractere
   printf("Digite o número de páginas: ");
   scanf("%d", &paginas);

   printf("\nVocê registrou o livro: '%s' de %s, com %d páginas.\n", livro, autor, paginas);
   return 0;
}
