#include <stdio.h>
#include "libs/limpa.h"
#define GUP 100

int main(void) {
    //Variaveis
      int idade, anos;
      char nome[GUP];
  limpatela();
  //Step 1: Nome
    printf("Informe o nome da pessoa: ");
    scanf("%[^\n]", nome);
  //Step 2: Idade
    printf("\nInforme a idade: ");
    scanf("%d", &idade);
  //Step 3: Processamento
    anos = 100 - idade;
  //Step 4: Resultado
    printf("\n\nFaltam %d anos para %s chegar aos 3 digitos na idade", anos, nome);
  return 0;
}
