#include <fcntl.h>
#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void re_read(FILE *fp);

void main(void)
{
	int fd;
	char buffer[500];
	ssize_t bytes_lidos;
	char fileb[64];
	
	strcpy(fileb, "Gong.bin");
	 
	 
	if((fd=open(fileb, O_RDONLY))==-1) {
		printf("O arquivo nao pode ser aberto \n");
		exit(1);
	}
	
	//if(read(fd, buffer, 100)!=100) printf("Erro de leitura");
	
	bytes_lidos = read(fd, buffer, sizeof(buffer) - 1); // Deixa espaço para o '\0'
    if (bytes_lidos == -1) {
        perror("Erro ao ler o arquivo");
        close(fd);
        return 1;
    }

    // Adicionar terminador nulo ao buffer para exibir como string
    buffer[bytes_lidos] = '\0';

    // Exibir o conteúdo lido
    printf("Conteudo lido em %s:\n%s\n", fileb, buffer);

    // Fechar o arquivo
    close(fd);
}

void re_read(FILE *fp)
{
	while(!feof(fp)) putchar((getc(fp)));
	
	rewind(fp);
	while(!feof(fp)) putchar((getc(fp)));
}
