#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(void)
{
  setlocale(LC_ALL, "Japanese");
  printf("日本語の漢字を使ってみましょう！\n\n");

  //system("pause");
  return 0;
}
