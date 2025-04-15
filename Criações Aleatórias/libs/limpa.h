#include <stdio.h>

void limparBuffer() {
  setbuf(stdin, NULL); 
}
void limpatela() {
  printf("\e[H\e[2J");
}
