#include <graphics.h>
#include <conio.h>
/*
int main() {
    int gd = DETECT, gm;
    int x = 100, y = 200; // Posi��o inicial do c�rculo
    int radius = 30;      // Raio do c�rculo
    int maxX;
    int step = 5;         // Passo do movimento do c�rculo

    initgraph(&gd, &gm, NULL); // Inicializa o sistema gr�fico
    maxX = getmaxx(); // Pega a largura m�xima da tela

    while (!kbhit()) { // Executa at� que uma tecla seja pressionada
        cleardevice(); // Limpa a tela
        setcolor(RED); // Define a cor do c�rculo para vermelho
        circle(x, y, radius); // Desenha o c�rculo na posi��o atual

        // Atualiza a posi��o x do c�rculo
        x += step;

        // Inverte a dire��o quando atinge as bordas da janela
        if (x > maxX - radius || x < radius) {
            step = -step;
        }

        delay(50); // Espera um pouco antes de continuar
    }

    getch(); // Espera que o usu�rio pressione uma tecla
    closegraph(); // Fecha o sistema gr�fico
    return 0;
}
*/
