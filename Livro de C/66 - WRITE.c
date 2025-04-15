#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void main(void){
	int fd;
	char buffer[500];
	
	if((fd=open("Gong.bin", O_CREAT | O_WRONLY))==-1)
	{
		printf("O arquivo nao pode ser aberto. \n");
		exit(1);
	}
	
	gets(buffer);
	
	if(write(fd, buffer, 500)!=500) printf("Erro de escrita");
	close(fd);
}
