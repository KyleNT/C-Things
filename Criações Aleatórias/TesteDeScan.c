#include <stdio.h>

int main() {
    char buffer[50];
    int num;

    printf("Digite um número: ");
    fgets(buffer, 50, stdin);
    num = atoi(buffer); // converte string para inteiro

    printf("Você digitou: %d\n", num);
    return 0;
}
