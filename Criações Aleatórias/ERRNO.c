#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *arquivo;
    const char *nome_arquivo = "arquivo_inexistente.txt";

    // Tenta abrir o arquivo para leitura
    arquivo = fopen(nome_arquivo, "r");

    // Verifica se houve erro
    if (arquivo == NULL) {
        // Usa errno para identificar o tipo de erro
        printf("Erro ao abrir o arquivo: %s\n", strerror(errno));
        
        // Mostra o número específico do erro (opcional)
        printf("Código do erro (errno): %d\n", errno);
        
        return 1; // Retorna erro
    }

    printf("Arquivo aberto com sucesso!\n");
    fclose(arquivo);
    
    return 0; // Sucesso
}
