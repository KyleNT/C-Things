#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> // Define a estrutura hostent

// Fun��o chamada quando uma chamada do sistema falha, exibindo uma mensagem de erro e abortando o programa
void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr; // Cont�m o endere�o do servidor ao qual queremos nos conectar
    struct hostent *server; // Ponteiro para uma estrutura do tipo hostent

    char buffer[256]; // Buffer para armazenar a mensagem
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }
    portno = atoi(argv[2]); // Converte o n�mero da porta de string para inteiro
    sockfd = socket(AF_INET, SOCK_STREAM, 0); // Cria um novo socket
    if (sockfd < 0) 
        error("ERRO abrindo o socket ");

    server = gethostbyname(argv[1]); // Obt�m o endere�o do servidor
    if (server == NULL) {
        fprintf(stderr,"ERRO, nenhum host \n");
        exit(0);
    }

    // Inicializa serv_addr com zeros e define os campos
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; // Define a fam�lia de endere�os como AF_INET
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length); // Copia o endere�o IP do servidor
    serv_addr.sin_port = htons(portno); // Converte o n�mero da porta para a ordem de bytes da rede

    // Estabelece uma conex�o com o servidor
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
        error("ERRO conectando ");

    // Solicita ao usu�rio que insira uma mensagem
    printf("Por favor insira a mensagem: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin); // L� a mensagem do usu�rio
    n = write(sockfd, buffer, strlen(buffer)); // Escreve a mensagem no socket
    if (n < 0) 
        error("ERRO escrevendo no socket");

    bzero(buffer, 256);
    n = read(sockfd, buffer, 255); // L� a resposta do servidor
    if (n < 0) 
        error("ERRO lendo do socket ");
    printf("%s\n", buffer);

    return 0;
} 

