#include <stdio.h> // Cont�m declara��es usadas na maioria das entradas e sa�das
#include <sys/types.h> // Cont�m defini��es de tipos de dados usados em chamadas do sistema
#include <sys/socket.h> // Inclui defini��es de estruturas necess�rias para sockets
#include <netinet/in.h> // Cont�m constantes e estruturas necess�rias para endere�os de dom�nio de internet

// Fun��o chamada quando uma chamada do sistema falha, exibindo uma mensagem de erro e abortando o programa
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    char buffer[256]; // Buffer onde o servidor l� caracteres da conex�o socket
    struct sockaddr_in serv_addr, cli_addr; // Estrutura contendo um endere�o de internet
    int n;

    // Verifica se o n�mero da porta foi passado como argumento
    if (argc < 2) {
        fprintf(stderr,"ERRO, nenhuma porta fornecida\n");
        exit(1);
    }

    // Cria um novo socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERRO na abertura do socket ");

    // Inicializa serv_addr com zeros
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]); // Converte o n�mero da porta de string para inteiro
    serv_addr.sin_family = AF_INET; // Define a fam�lia de endere�os como AF_INET
    serv_addr.sin_addr.s_addr = INADDR_ANY; // Define o endere�o IP do servidor
    serv_addr.sin_port = htons(portno); // Converte o n�mero da porta para a ordem de bytes da rede

    // Associa o socket a um endere�o
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERRO na associacao ");

    // Escuta por conex�es no socket
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // Aceita uma conex�o
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) 
        error("ERRO no aceite ");

    // Inicializa o buffer e l� do socket
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0) 
        error("ERRO lendo do socket ");
    printf("Aqui esta a mensagem: %s\n", buffer);

    // Escreve no socket
    n = write(newsockfd, "Eu obtive sua mensagem ", 18);
    if (n < 0) 
        error("ERRO escrevendo no socket ");

    return 0;
} 

