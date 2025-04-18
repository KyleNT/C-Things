#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int size, i;

    printf("Quantos numeros voce deseja inserir? ");
    scanf("%d", &size);

    // Aloca��o din�mica de mem�ria
    array = (int*) malloc(size * sizeof(int));

    // Verifica��o de aloca��o bem-sucedida
    if (array == NULL) {
        printf("Erro de aloca��o de memoria.\n");
        return -1; // Encerra o programa com erro
    }

    // Inser��o de n�meros no array
    for (i = 0; i < size; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Exibi��o dos n�meros
    printf("Voce inseriu: ");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    // Libera��o da mem�ria alocada
    free(array);
    
    return 0;
}
