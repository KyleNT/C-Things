#include <stdio.h>  // Biblioteca-padr�o de entrada e sa�da
#include <stdlib.h> // Biblioteca-padr�o de fun��es utilit�rias
#include <unistd.h> // Biblioteca para chamadas ao sistema Posix (como sleep)
#include <pthread.h> // Biblioteca para manipula��o de threads
  
// Uma fun��o normal em C que � executada como um thread
// quando seu nome � especificado em pthread_create()
void *helloWorld(void *vargp)
{
    sleep(1); // Faz o thread dormir por 1 segundo
    printf("Alo mundo \n"); // Imprime "Hello World" na tela
    return NULL; // Retorna Null ao terminar a execu��o do thread
}
   
int main()
{
    pthread_t thread_id; // Declara��o de uma vari�vel para armazenar o ID do thread
    printf("Before Thread\n"); // Imprime antes de criar o thread
    pthread_create(&thread_id, NULL, helloWorld, NULL); // Cria um novo thread que executa a fun��o helloWorld
    pthread_join(thread_id, NULL); // Espera at� que o thread especificado termine
    printf("Ap�s a Thread\n"); // Imprime ap�s o thread ter terminado
    exit(0); // Encerra o programa
} 
