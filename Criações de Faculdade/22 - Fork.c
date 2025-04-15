#include <stdlib.h> /* necessário para definir exit() */
#include <unistd.h> /* necessário para fork() e getpid() */
#include <stdio.h>  /* necessário para printf() */

int main(int argc, char **argv) {
    int pid; /* process ID */

    switch (pid = fork()) {
    case 0: /* um fork retorna 0 para o filho */
        printf("Eu sou o processo-filho: pid=%d\n", getpid());
        break;

    default: /* um fork retorna um pid para o pai */
        printf("Eu sou o processo-pai: pid=%d, child pid=%d\n", getpid(), pid);
        break;

    case -1: /* algo deu errado */
        perror("fork");
        exit(1);
    }
    exit(0);
} 

