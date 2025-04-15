#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 128

void main(int argc, char *argv[])
{
	char buf[BUF_SIZE], s[10];
	int fd, sector;
	
	buf[BUF_SIZE] = '\0';
	
	if((fd=open(argv[1], O_RDONLY))==-1)
	{
		printf("O arquivo nao pode ser aberto. \n");
		exit(1);
	}
	
	do{
		printf("Buffer: ");
		gets(s);
		
		sector = atoi(s);
		
		if(lseek(fd, (long)sector*BUF_SIZE, SEEK_SET)==-1L)
			printf("Erro na busca. \n");
			
		if(read(fd, buf, BUF_SIZE)==0) {
			printf("Setor fora da faixa. \n");
		}
		else
			printf("%s\n", buf);
	} while(sector>0);
	
	close(fd);
}
