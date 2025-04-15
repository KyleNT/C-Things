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
glBegin(GL_POLYGON) at� glEnd(): delimitam a defini��o de um pol�gono. Entre glBegin e glEnd, chamadas de glVertex2f especificam os v�rtices do pol�gono. Modifica o estado de renderiza��o para definir a geometria que ser� desenhada.
glFlush(): garante que todos os comandos de OpenGL anteriores sejam executadas o mais r�pido poss�vel. Manipula o estado de buffer.
*/


int main(void) {
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutCreateWindow("Ola Mundo"); 
glutDisplayFunc(display);
glutMainLoop();
}

/*
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB): configura o modo de exibi��o da janela. GLUT_SINGLE indica o uso de um �nico buffer de exibi��o, e GLUT_RGB define que a janela utilizar� um modelo de cor RGB. Isso configura os estados da janela de exibi��o.
glutCreateWindow("Ola Mundo"): cria uma janela com o t�tulo "Ola Mundo".
glutDisplayFunc(display): registra a fun��o display como a de callback que ser� chamada para redesenhar a janela. Isso n�o altera diretamente o estado do OpenGL, mas define como o estado deve ser gerenciado quando a janela precisa ser atualizada.
glutMainLoop(): inicia o loop de processamento de eventos da GLUT, que gerencia a exibi��o e os outros eventos de entrada, mantendo a aplica��o ativa.
*/
