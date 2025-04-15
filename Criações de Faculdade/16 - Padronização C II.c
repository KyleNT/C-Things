#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main(){
	
	int fd = open("Treu.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	const char *text = "Some Troy";
	ssize_t bytes_written = write(fd, text, strlen(text)); 

	return 0;
}
