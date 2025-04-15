#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

// Função que será executada por cada thread
void *perform_operation(void *arg) {
    int thread_id = *(int *)arg; // Obtém o ID do thread a partir do argumento
    int result = 0;

    // Simula diferentes operações matemáticas baseadas no ID do thread
    switch(thread_id) {
        case 0:
            result = thread_id * 3; // Exemplo: multiplicação
            printf("Thread %d: Resultado da multiplicacao = %d\n", thread_id, result);
            break;
        case 1:
            result = thread_id + 3; // Exemplo: adição
            printf("Thread %d: Resultado da adicao = %d\n", thread_id, result);
            break;
        case 2:
            result = thread_id - 3; // Exemplo: subtração
            printf("Thread %d: Resultado da subtracao = %d\n", thread_id, result);
            break;
        case 3:
            result = thread_id * thread_id; // Exemplo: quadrado
            printf("Thread %d: Resultado do quadrado = %d\n", thread_id, result);
            break;
        case 4:
            result = thread_id * 4; // Exemplo: multiplicação por 4
            printf("Thread %d: Resultado da multiplicacao por 4 = %d\n", thread_id, result);
            break;
        default:
            printf("Thread %d: Nenhuma operação atribuída\n", thread_id);
            break;
    }

    pthread_exit(NULL); // Encerra o thread
}

int main() {
    pthread_t threads[NUM_THREADS]; // Array para armazenar os identificadores dos threads
    int thread_ids[NUM_THREADS]; // Array para armazenar os IDs dos threads
    int rc;

    // Cria os threads
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i; // Define o ID do thread
        rc = pthread_create(&threads[i], NULL, perform_operation, (void *)&thread_ids[i]); // Cria um novo thread
        if (rc) {
            printf("Erro: Não foi possível criar o thread %d\n", i); // Mensagem de erro em caso de falha na criação do thread
            exit(-1); // Encerra o programa com um código de erro
        }
    }

    // Espera que todos os threads completem suas operações
    int j;
    for (j = 0; j < NUM_THREADS; j++) {
        pthread_join(threads[j], NULL);
    }

    printf("Todos os threads concluíram suas operações.\n"); // Mensagem indicando que todos os threads finalizaram
    return 0;
} 
