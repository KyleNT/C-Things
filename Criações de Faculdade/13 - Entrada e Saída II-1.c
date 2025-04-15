#include <stdio.h>

int main(void) {
    int i;
    for (i = 1; i < 8; i++)
        printf("%8d %8d %8d\n", i, i * i, i * i * i);
        
    printf("justificado a direita: %8d\n", 100);
    printf("justificado a esquerda: %-8d\n", 100);
    
    return 0;
} 

