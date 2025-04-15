
#include <pthread.h> // Biblioteca para manipulação de threads
#include <stdio.h> // Biblioteca-padrão de entrada e saída

#define NUM_THREADS 5 // Define o número de threads como 5

// Função que será executada como um thread
void *PrintHello(void *threadid) {
    long tid;
    tid = (long)threadid; // Converte o identificador do thread para um long
    printf("Alo mundo! Sou eu, thread #%ld!\n", tid); // Imprime o identificador do thread
    pthread_exit(NULL); // Encerra o thread
}

int main (int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS]; // Declaração de um array para armazenar os IDs dos threads
    int rc;
    long t;

    // Cria múltiplos threads
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Em main: criando thread %ld\n", t); // Imprime a criação do thread
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t); // Cria um novo thread que executa a função PrintHello
        if (rc) {
            printf("ERRO; código de retorno de pthread_create() eh %d\n", rc); // Imprime mensagem de erro se pthread_create falhar
            exit(-1); // Encerra o programa em caso de erro
        }
    }

    /* A última coisa que a função main() deve fazer */
    pthread_exit(NULL); // Aguarda que todas os threads terminem antes de encerrar o programa
} 
