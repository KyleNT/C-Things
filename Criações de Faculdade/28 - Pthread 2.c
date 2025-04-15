#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

// Fun��o que ser� executada por cada thread
void *perform_operation(void *arg) {
    int thread_id = *(int *)arg; // Obt�m o ID do thread a partir do argumento
    int result = 0;

    // Simula diferentes opera��es matem�ticas baseadas no ID do thread
    switch(thread_id) {
        case 0:
            result = thread_id * 3; // Exemplo: multiplica��o
            printf("Thread %d: Resultado da multiplicacao = %d\n", thread_id, result);
            break;
        case 1:
            result = thread_id + 3; // Exemplo: adi��o
            printf("Thread %d: Resultado da adicao = %d\n", thread_id, result);
            break;
        case 2:
            result = thread_id - 3; // Exemplo: subtra��o
            printf("Thread %d: Resultado da subtracao = %d\n", thread_id, result);
            break;
        case 3:
            result = thread_id * thread_id; // Exemplo: quadrado
            printf("Thread %d: Resultado do quadrado = %d\n", thread_id, result);
            break;
        case 4:
            result = thread_id * 4; // Exemplo: multiplica��o por 4
            printf("Thread %d: Resultado da multiplicacao por 4 = %d\n", thread_id, result);
            break;
        default:
            printf("Thread %d: Nenhuma opera��o atribu�da\n", thread_id);
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
            printf("Erro: N�o foi poss�vel criar o thread %d\n", i); // Mensagem de erro em caso de falha na cria��o do thread
            exit(-1); // Encerra o programa com um c�digo de erro
        }
    }

    // Espera que todos os threads completem suas opera��es
    int j;
    for (j = 0; j < NUM_THREADS; j++) {
        pthread_join(threads[j], NULL);
    }

    printf("Todos os threads conclu�ram suas opera��es.\n"); // Mensagem indicando que todos os threads finalizaram
    return 0;
} 
