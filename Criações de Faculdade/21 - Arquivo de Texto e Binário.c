#include <stdio.h>

int main() {

    FILE *fpTexto, *fpBinario; //Declaração de texto e binário
    char nome[100];
    int contador = 0;

    // Abertura dos arquivos
    fpTexto = fopen("touhouchar.txt", "a+"); //Abre ou cria arquivo de texto
    fpBinario = fopen("countertouhou.bin", "rb+"); //Abre o ninário no modo leitura

    if (fpBinario == NULL) { // Arquivo binário não existe, criá-lo
        fpBinario = fopen("countertouhou.bin", "wb+");
       fwrite(&contador, sizeof(int), 1, fpBinario); //Escreve o valor inicial

    } else { // Ler o contador existente
       fread(&contador, sizeof(int), 1, fpBinario); //Lê o valor do contador
    }



   printf("Digite o nome da Personagem de Touhou: ");
   scanf(" %[^\n]", nome);
   fprintf(fpTexto, "%s\n", nome); // Escreve o nome no arquivo de texto formatado
   contador++;
   rewind(fpBinario); //Volta para o início do binário
   fwrite(&contador, sizeof(int), 1, fpBinario); // Atualiza o contador no arquivo binário

    // Fechamento dos arquivos
    fclose(fpTexto);
    fclose(fpBinario);

    printf("Total de participantes registrados: %d\n", contador);

    return 0;

}
