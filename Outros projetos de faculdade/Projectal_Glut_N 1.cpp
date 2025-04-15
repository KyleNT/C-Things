#include<glut.h> 

void display(void) 
{
glClear(GL_COLOR_BUFFER_BIT); 
glBegin(GL_POLYGON);
glVertex2f(-0.3, -0.3); 
glVertex2f(-0.3, 0.3); 
glVertex2f(0.3, 0.3); 
glVertex2f(0.3, -0.3);
glEnd();
glFlush();
}

/*
glClear(GL_COLOR_BUFFER_BIT): limpa o buffer de cor da janela para preparar para o novo desenho. Configura um estado do OpenGL para limpeza de tela.
glBegin(GL_POLYGON) até glEnd(): delimitam a definição de um polígono. Entre glBegin e glEnd, chamadas de glVertex2f especificam os vértices do polígono. Modifica o estado de renderização para definir a geometria que será desenhada.
glFlush(): garante que todos os comandos de OpenGL anteriores sejam executadas o mais rápido possível. Manipula o estado de buffer.
*/


int main(void) {
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutCreateWindow("Ola Mundo"); 
glutDisplayFunc(display);
glutMainLoop();
}

/*
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB): configura o modo de exibição da janela. GLUT_SINGLE indica o uso de um único buffer de exibição, e GLUT_RGB define que a janela utilizará um modelo de cor RGB. Isso configura os estados da janela de exibição.
glutCreateWindow("Ola Mundo"): cria uma janela com o título "Ola Mundo".
glutDisplayFunc(display): registra a função display como a de callback que será chamada para redesenhar a janela. Isso não altera diretamente o estado do OpenGL, mas define como o estado deve ser gerenciado quando a janela precisa ser atualizada.
glutMainLoop(): inicia o loop de processamento de eventos da GLUT, que gerencia a exibição e os outros eventos de entrada, mantendo a aplicação ativa.
*/
