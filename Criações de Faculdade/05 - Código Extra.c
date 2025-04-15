#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int size, i;

    printf("Quantos numeros voce deseja inserir? ");
    scanf("%d", &size);

    // Alocação dinâmica de memória
    array = (int*) malloc(size * sizeof(int));

    // Verificação de alocação bem-sucedida
    if (array == NULL) {
        printf("Erro de alocação de memoria.\n");
        return -1; // Encerra o programa com erro
    }

    // Inserção de números no array
    for (i = 0; i < size; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Exibição dos números
    printf("Voce inseriu: ");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    // Liberação da memória alocada
    free(array);
    
    return 0;
}
