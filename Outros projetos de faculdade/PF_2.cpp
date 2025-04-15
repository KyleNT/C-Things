#include <graphics.h>
#include <conio.h>
#include <stdlib.h> // Para rand() e srand()
#include <time.h>   // Para time()


int main() {
    int gd = DETECT, gm;
    int x = 300, y = 200; // Posição inicial do círculo
    int radius = 30;      // Raio do círculo
    int maxX, maxY;
    int dx = 4, dy = 4;   // Componentes de velocidade iniciais

    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    initgraph(&gd, &gm, NULL); // Inicializa o sistema gráfico
    maxX = getmaxx(); // Pega a largura máxima da tela
    maxY = getmaxy(); // Pega a altura máxima da tela

    while (!kbhit()) { // Executa até que uma tecla seja pressionada
        cleardevice(); // Limpa a tela
        setcolor(RED); // Define a cor do círculo para vermelho
        circle(x, y, radius); // Desenha o círculo na posição atual

        // Atualiza a posição do círculo
        x += dx;
        y += dy;

        // Verifica se o círculo atinge as bordas e ajusta a direção
        if (x > maxX - radius || x < radius) {
            dx = -dx + (rand() % 8-4); // Inverte e ajusta aleatoriamente a direção horizontal
        }
        if (y > maxY - radius || y < radius) {
            dy = -dy + (rand() % 8-4); // Inverte e ajusta aleatoriamente a direção vertical
        }

        delay(50); // Espera um pouco antes de continuar
    }

    getch(); // Espera que o usuário pressione uma tecla
    closegraph(); // Fecha o sistema gráfico
    return 0;
}
