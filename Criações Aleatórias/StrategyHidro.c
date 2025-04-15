#include <stdio.h>
#include <stdbool.h>

// Definindo o tipo da função que será nossa "estratégia"
typedef bool (*CondicaoStrategy)(int walter, int idade);

// Estrutura que representa o contexto, que usa uma estratégia
typedef struct {
    CondicaoStrategy avaliar; // Ponteiro para a função estratégia
} Contexto;

// Estratégia 1:
bool estrategia1(int walter, int idade) {
    return (walter <= 10 && idade >= 13);
}

// Estratégia 2:
bool estrategia2(int walter, int idade) {
    return (walter < 10 && idade < 13);
}

bool estrategia3(int walter, int idade) {
    return (walter <= 20 && idade >= 13);
}

bool estrategia4(int walter, int idade) {
    return (walter < 20 && idade < 13);
}

bool estrategia5(int walter, int idade) {
    return (walter <= 30 && idade >= 13);
}

bool estrategia6(int walter, int idade) {
    return (walter < 30 && idade < 13);
}

bool estrategia7(int walter, int idade) {
    return (walter <= 40 && idade >= 13);
}

bool estrategia8(int walter, int idade) {
    return (walter < 40 && idade < 13);
}

bool estrategia9(int walter, int idade) {
    return (walter <= 50 && idade >= 13);
}

bool estrategia10(int walter, int idade) {
    return (walter < 50 && idade < 13);
}

bool estrategia11(int walter, int idade) {
    return (walter <= 60 && idade >= 13);
}

bool estrategia12(int walter, int idade) {
    return (walter < 60 && idade < 13);
}

bool estrategia13(int walter, int idade) {
    return (walter <= 70 && idade >= 13);
}

bool estrategia14(int walter, int idade) {
    return (walter > 70 && idade < 13);
}

bool estrategia15(int walter, int idade) {
    return (walter <= 80 && idade >= 13);
}
bool estrategia16(int walter, int idade) {
    return (walter < 80 && idade < 13);
}

bool estrategiaPadrao(int a, int b) {
    printf("Voce e sigma e tem o molho.\n");
    return false; // Comportamento padrão, pode ser ajustado
}

// Função que usa o contexto para avaliar a condição
bool avaliarCondicao(Contexto* ctx, int walter, int idade) {
    return ctx->avaliar(walter, idade); // Chama a estratégia configurada
}

// Função para configurar a estratégia no contexto
void setEstrategia(Contexto* ctx, CondicaoStrategy estrategia) {
    if (estrategia != NULL) {
        ctx->avaliar = estrategia;
    } else {
        ctx->avaliar = estrategiaPadrao; // Garante que sempre tenha uma estratégia válida
    }
}
// Função para inicializar o contexto com a estratégia padrão
void inicializarContexto(Contexto* ctx) {
    ctx->avaliar = estrategiaPadrao; // "else" padrão no início
}


int main() {
    // Criando o contexto
    Contexto ctx;

    // Configurando a primeira estratégia (a < 5 && b > 6)
    setEstrategia(&ctx, estrategia1);
    
    // Testando com valores
    int a = 10, b = 13;
    printf("Strategy I (a <= 10 && b >= 13) com a=%d, b=%d: %s\n", 
           a, b, avaliarCondicao(&ctx, a, b) ? "Verdadeiro" : "Falso");

    // Mudando para a segunda estratégia em tempo de execução
    setEstrategia(&ctx, estrategia2);
    printf("Strategy II (a < 10 && b < 13) com a=%d, b=%d: %s\n", 
           a, b, avaliarCondicao(&ctx, a, b) ? "Verdadeiro" : "Falso");
	
    setEstrategia(&ctx, estrategia3);
    printf("Strategy III (a <= 20 && b >= 13) com a=%d, b=%d: %s\n", 
           a, b, avaliarCondicao(&ctx, a, b) ? "Verdadeiro" : "Falso");
           
    setEstrategia(&ctx, estrategia4);
    printf("Strategy IV (a < 20 && b < 13) com a=%d, b=%d: %s\n", 
           a, b, avaliarCondicao(&ctx, a, b) ? "Verdadeiro" : "Falso");
           
    setEstrategia(&ctx, estrategia5);
    printf("Strategy V (a <= 30 && b >= 13) com a=%d, b=%d: %s\n", 
           a, b, avaliarCondicao(&ctx, a, b) ? "Verdadeiro" : "Falso");
           
    setEstrategia(&ctx, estrategia6);
    printf("Strategy VI (a < 30 && b < 13) com a=%d, b=%d: %s\n", 
           a, b, avaliarCondicao(&ctx, a, b) ? "Verdadeiro" : "Falso");

    setEstrategia(&ctx, estrategia7);
    printf("Strategy VII (a <= 40 && b >= 13) com a=%d, b=%d: %s\n", 
           a, b, avaliarCondicao(&ctx, a, b) ? "Verdadeiro" : "Falso");
           
    setEstrategia(&ctx, estrategia8);
    printf("Strategy VIII (a < 40 && b < 13) com a=%d, b=%d: %s\n", 
           a, b, avaliarCondicao(&ctx, a, b) ? "Verdadeiro" : "Falso");
	
    setEstrategia(&ctx, estrategia9);
    printf("Strategy IX (a <= 50 && b >= 13) com a=%d, b=%d: %s\n", 
           a, b, avaliarCondicao(&ctx, a, b) ? "Verdadeiro" : "Falso");
           
    setEstrategia(&ctx, estrategia10);
    printf("Strategy X (a < 50 && b < 13) com a=%d, b=%d: %s\n", 
           a, b, avaliarCondicao(&ctx, a, b) ? "Verdadeiro" : "Falso");
           
    setEstrategia(&ctx, estrategia11);
    printf("Strategy XI (a <= 60 && b >= 13) com a=%d, b=%d: %s\n", 
           a, b, avaliarCondicao(&ctx, a, b) ? "Verdadeiro" : "Falso");
           
    setEstrategia(&ctx, estrategia12);
    printf("Strategy XII (a < 60 && b < 13) com a=%d, b=%d: %s\n", 
           a, b, avaliarCondicao(&ctx, a, b) ? "Verdadeiro" : "Falso");

    setEstrategia(&ctx, estrategia13);
    printf("Strategy XIII (a <= 70 && b >= 13) com a=%d, b=%d: %s\n", 
           a, b, avaliarCondicao(&ctx, a, b) ? "Verdadeiro" : "Falso");
           
    setEstrategia(&ctx, estrategia14);
    printf("Strategy XIV (a < 70 && b < 13) com a=%d, b=%d: %s\n", 
           a, b, avaliarCondicao(&ctx, a, b) ? "Verdadeiro" : "Falso");
           
    setEstrategia(&ctx, estrategia15);
    printf("Strategy XV (a <= 80 && b >= 13) com a=%d, b=%d: %s\n", 
           a, b, avaliarCondicao(&ctx, a, b) ? "Verdadeiro" : "Falso");
           
    setEstrategia(&ctx, estrategia16);
    printf("Strategy XVI (a < 80 && b < 13) com a=%d, b=%d: %s\n", 
           a, b, avaliarCondicao(&ctx, a, b) ? "Verdadeiro" : "Falso");
           
    setEstrategia(&ctx, NULL); // Simula "nenhuma estratégia específica"
    printf("Teste com padrão (NULL): a=%d, b=%d: %s\n", 
           a, b, avaliarCondicao(&ctx, a, b) ? "Verdadeiro" : "Falso");

    return 0;
}
