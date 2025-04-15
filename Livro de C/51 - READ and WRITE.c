#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <string.h>
#include <fnctl.h>

#define BUF_SIZE 128

void input(char *buf, int fd1);
void display(char *buf, int fd2);

void main(void)
{
	char buf[BUF_SIZE];
	int fd1, fd2;
	
	if((fd1=open("Afghan.txt", O_WRONLY)) == -1) {
		printf("O arquivo nao pode ser aberto. \n");
		exit(1);
	}
	
	input(buf, fd1);
	close(fd1);
	
	if((fd1=open("Afghan.txt", O_RDONLY)) == -1) {
		printf("O arquivo nao pode ser aberto. \n");
		exit(1);
	}
	
	display(buf, fd2);
	close(fd2);
}

void input(char *buf, int fd1)
{
	register int t;
	do {
		for(t=0;t<BUF_SIZE;t++) buf[t] = '\0';
		gets(buf);
		if(write(fd1, buf, BUF_SIZE) != BUF_SIZE) {
			printf("Erro de escrita. \n");
			exit(1);
		}
	} while(strcmp(buf, "quit"));
}

void display(char *buf, int fd2)
{
	for(;;) {
		if(read(fd2, buf, BUF_SIZE)==0) return;
		printf("%\n", buf);
	}
}
