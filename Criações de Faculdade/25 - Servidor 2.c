#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Fun��o para lidar com mensagens de erro
void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    pid_t pid;

    // Verifica se o n�mero da porta foi fornecido como argumento
    if (argc < 2) {
        fprintf(stderr, "ERRO, porta n�o fornecida\n");
        exit(1);
    }

    // Cria��o do socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERRO ao abrir o socket");
    }

    // Zera a estrutura do endere�o do servidor
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]); // Converte o n�mero da porta de string para inteiro

    serv_addr.sin_family = AF_INET; // Define a fam�lia de endere�os
    serv_addr.sin_addr.s_addr = INADDR_ANY; // Aceita conex�es de qualquer endere�o IP
    serv_addr.sin_port = htons(portno); // Define o n�mero da porta

    // Associa o socket a um endere�o (IP e porta)
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERRO ao associar");
    }

    // Escuta por conex�es, com uma fila de espera de at� 5 conex�es
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // Loop infinito para aceitar conex�es
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            error("ERRO na aceita��o");
        }
        // Cria��o de um novo processo para cada conex�o
        pid = fork();
        if (pid < 0) {
            error("ERRO na cria��o do fork");
        }
        // Processo-filho
        if (pid == 0) {
            close(sockfd); // Fecha o socket original no processo-filho
            char buffer[256];
            bzero(buffer, 256); // Zera o buffer
            read(newsockfd, buffer, 255); // L� dados do socket
            printf("Aqui est� a mensagem: %s\n", buffer); // Exibe a mensagem recebida
            write(newsockfd, "Recebi sua mensagem", 18); // Envia resposta para o cliente
            close(newsockfd); // Fecha o novo socket
            exit(0); // Encerra o processo-filho
        } else {
            close(newsockfd); // Processo-pai fecha o novo socket
        }
    }
    close(sockfd); // Fecha o socket original
    return 0;
} 
