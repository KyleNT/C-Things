#include <glut.h>

void pyramid()
{
glBegin( GL_TRIANGLES );

    // Frente
    glColor3f(1.0, 1.0, 1.0); // Vermelho
    glVertex3f(0.0, 1.0, 0.0); // V�rtice superior
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);

    // Direita
    glColor3f(1.0, 1.0, 1.0); // Verde
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);

    // Traseira
    glColor3f(1.0, 1.0, 1.0); // Azul
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);

    // Esquerda
    glColor3f(1.0, 1.0, 1.0); // Amarelo
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);

    glEnd(); // Fim do desenho da pir�mide


}

// Fun��o chamada para desenhar
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Posiciona a c�mera
    gluLookAt(3.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Rota��o simples ao redor do eixo Y
    static float angle = 0.0;
    glRotatef(angle, 0.0, 1.0, 0.0);

    // Desenha o cubo
    
	glutSolidCube(1.5);

	//glutSolidTetrahedron();
	
	
    // Atualiza o �ngulo
    angle += 0.2;
    if (angle > 360) angle = 0;

    glutSwapBuffers();
}

// Inicializa par�metros de rendering
void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    // Define a cor do fundo
    glClearColor(0.1, 0.1, 0.1, 1.0);

    // Configura��o da ilumina��o
    GLfloat lightPos[] = {1.0, 1.0, 1.0, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}

// Chamado quando a janela � redimensionada
void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    // Inicializa GLUT e processa os argumentos do usu�rio
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // Configura o tamanho e a posi��o inicial da janela
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);

    // Cria a janela
    glutCreateWindow("Exemplo de Cubo 3D OpenGL");

    // Inicializa alguns par�metros de rendering
    initRendering();

    // Configura as fun��es de callback
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(handleResize);

    // Come�a o loop principal
    glutMainLoop();
    return 0;
}


/* Fun��o Display
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT): limpa os buffers de cor e profundidade para preparar para um novo quadro, garantindo que n�o haja res�duos visuais de desenhos anteriores.
glLoadIdentity(): restaura a matriz de transforma��o para o estado padr�o (identidade), garantindo que as transforma��es n�o se acumulem entre os quadros.
gluLookAt(3.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0): define a posi��o da c�mera. Os tr�s primeiros valores s�o a posi��o da c�mera no espa�o, os tr�s seguintes s�o as coordenadas para onde ela est� olhando, e os �ltimos tr�s definem a orienta��o vertical da c�mera.
glRotatef(angle, 0.0, 1.0, 0.0): aplica uma rota��o em torno do eixo Y (vertical) ao cubo, no qual angle � o �ngulo de rota��o.
glutSolidCube(1.5): desenha um cubo s�lido com comprimento de aresta 1.5 unidades.
angle += 0.2: atualiza o �ngulo para a pr�xima renderiza��o, incrementando-o pela velocidade definida.
if (angle > 360) angle -= 36: garante que o valor do �ngulo n�o cres�a indefinidamente.
glutSwapBuffers(): troca os buffers de fundo para os de frente, exibindo o quadro renderizado e iniciando o desenho do pr�ximo quadro no buffer oculto.
*/

/* Fun��o initiRendering
glEnable(GL_DEPTH_TEST): habilita o teste de profundidade, que ajuda a garantir que superf�cies sejam corretamente ocultadas por outras que est�o � frente delas.
glEnable(GL_LIGHTING) e glEnable(GL_LIGHT0): habilitam a ilumina��o e a primeira fonte de luz, respectivamente, para adicionar efeitos de luz e sombra.
glEnable(GL_NORMALIZE) e glEnable(GL_COLOR_MATERIAL): as normais s�o vetores perpendiculares � superf�cie dos objetos em um cen�rio 3D. Eles s�o essenciais para o c�lculo da ilumina��o, pois determinam como a luz interage com a superf�cie. Em OpenGL, quando um objeto � transformado (escalado, rotacionado ou transladado), suas normais tamb�m sofrem transforma��es. Para assegurar que elas sejam corretamente ajustadas e continuem a representar vetores unit�rios (de comprimento 1), utiliza-se o comando glEnable(GL_NORMALIZE). A fun��o glEnable(GL_COLOR_MATERIAL) permite que as cores dos materiais dos objetos reajam corretamente � ilumina��o.
glClearColor(0.1, 0.1, 0.1, 1.0): define a cor de fundo.
glLightfv(GL_LIGHT0, GL_POSITION, lightPos): estabelece a posi��o da fonte de luz.
*/

/* Fun��o handleResize
glViewport(0, 0, w, h): ajusta a �rea de desenho para o tamanho atual da janela.
glMatrixMode(GL_PROJECTION) e glMatrixMode(GL_MODELVIEW): alternam entre modificar a matriz de proje��o e a matriz de modelo/vista, respectivamente.
gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0): define a perspectiva da c�mera com um campo de vis�o de 45 graus e um aspecto baseado no tamanho da janela.
*/

/* Fun��o main
glutInit e fun��es relacionadas configuram a janela e o modo de exibi��o.
glutDisplayFunc(display) e glutIdleFunc(display): definem a fun��o display como a fun��o de callback para desenhar e atualizar a janela.
glutMainLoop(): inicia o loop de eventos da GLUT.
*/


