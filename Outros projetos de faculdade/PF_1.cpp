#include <graphics.h>
#include <conio.h>
/*
int main() {
    int gd = DETECT, gm;
    int x = 100, y = 200; // Posição inicial do círculo
    int radius = 30;      // Raio do círculo
    int maxX;
    int step = 5;         // Passo do movimento do círculo

    initgraph(&gd, &gm, NULL); // Inicializa o sistema gráfico
    maxX = getmaxx(); // Pega a largura máxima da tela

    while (!kbhit()) { // Executa até que uma tecla seja pressionada
        cleardevice(); // Limpa a tela
        setcolor(RED); // Define a cor do círculo para vermelho
        circle(x, y, radius); // Desenha o círculo na posição atual

        // Atualiza a posição x do círculo
        x += step;

        // Inverte a direção quando atinge as bordas da janela
        if (x > maxX - radius || x < radius) {
            step = -step;
        }

        delay(50); // Espera um pouco antes de continuar
    }

    getch(); // Espera que o usuário pressione uma tecla
    closegraph(); // Fecha o sistema gráfico
    return 0;
}
*/
