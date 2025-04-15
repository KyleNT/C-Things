#include <stdio.h>
#include <assert.h>

//
// Função mdc
//
int mdc(int num1, int num2) {

    int resto;

    do {
        resto = num1 % num2;

        num1 = num2;
        num2 = resto;

    } while (resto != 0);

    return num1;
}

//
// Testes
//
int main() {

	int a = 60, b = 48, c = 48;
    int bola = mdc(mdc(a,b),c);
    printf("MDC de %d, %d e %d: ", a, b, c);
    printf("%d",bola);

    return 0;
}
