#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <fnctl.h>

#define BUF_SIZE 128

void main(int argc, char *argv[])
{
	char buf[BUF_SIZE+1], s[10];
	int fd, sector;
	
	if(argc!=2)
	{
		printf("Uso: dump <sector> \n");
		exit(1);
	}
	
	buf[BUF_SIZE] = '\0';
	
	if((fd=open(argv[1], O_RDONLY))==-1)
	{
		printf("Arquivo nao pode ser aberto. \n");
		exit(1);
	}
	
	do{
		printf("\nBuffer: ");
		gets(s);
		
		sector = atoi(s);
		
		if(lseek(fd, (long)sector*BUF_SIZE, 0)==-1L)
			printf("Erro na busca\n");
			
		if(read(fd, buf, BUF_SIZE)==0) {
			printf("Setor fora da caixa\n");
		} else 
		{
			printf(buf);
		}
	} while(sector>=0);
	close(fd);
}
