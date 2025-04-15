#include <glut.h>

void pyramid()
{
glBegin( GL_TRIANGLES );

    // Frente
    glColor3f(1.0, 1.0, 1.0); // Vermelho
    glVertex3f(0.0, 1.0, 0.0); // Vértice superior
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

    glEnd(); // Fim do desenho da pirâmide


}

// Função chamada para desenhar
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Posiciona a câmera
    gluLookAt(3.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Rotação simples ao redor do eixo Y
    static float angle = 0.0;
    glRotatef(angle, 0.0, 1.0, 0.0);

    // Desenha o cubo
    
	glutSolidCube(1.5);

	//glutSolidTetrahedron();
	
	
    // Atualiza o ângulo
    angle += 0.2;
    if (angle > 360) angle = 0;

    glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    // Define a cor do fundo
    glClearColor(0.1, 0.1, 0.1, 1.0);

    // Configuração da iluminação
    GLfloat lightPos[] = {1.0, 1.0, 1.0, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}

// Chamado quando a janela é redimensionada
void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    // Inicializa GLUT e processa os argumentos do usuário
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // Configura o tamanho e a posição inicial da janela
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);

    // Cria a janela
    glutCreateWindow("Exemplo de Cubo 3D OpenGL");

    // Inicializa alguns parâmetros de rendering
    initRendering();

    // Configura as funções de callback
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(handleResize);

    // Começa o loop principal
    glutMainLoop();
    return 0;
}


/* Função Display
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT): limpa os buffers de cor e profundidade para preparar para um novo quadro, garantindo que não haja resíduos visuais de desenhos anteriores.
glLoadIdentity(): restaura a matriz de transformação para o estado padrão (identidade), garantindo que as transformações não se acumulem entre os quadros.
gluLookAt(3.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0): define a posição da câmera. Os três primeiros valores são a posição da câmera no espaço, os três seguintes são as coordenadas para onde ela está olhando, e os últimos três definem a orientação vertical da câmera.
glRotatef(angle, 0.0, 1.0, 0.0): aplica uma rotação em torno do eixo Y (vertical) ao cubo, no qual angle é o ângulo de rotação.
glutSolidCube(1.5): desenha um cubo sólido com comprimento de aresta 1.5 unidades.
angle += 0.2: atualiza o ângulo para a próxima renderização, incrementando-o pela velocidade definida.
if (angle > 360) angle -= 36: garante que o valor do ângulo não cresça indefinidamente.
glutSwapBuffers(): troca os buffers de fundo para os de frente, exibindo o quadro renderizado e iniciando o desenho do próximo quadro no buffer oculto.
*/

/* Função initiRendering
glEnable(GL_DEPTH_TEST): habilita o teste de profundidade, que ajuda a garantir que superfícies sejam corretamente ocultadas por outras que estão à frente delas.
glEnable(GL_LIGHTING) e glEnable(GL_LIGHT0): habilitam a iluminação e a primeira fonte de luz, respectivamente, para adicionar efeitos de luz e sombra.
glEnable(GL_NORMALIZE) e glEnable(GL_COLOR_MATERIAL): as normais são vetores perpendiculares à superfície dos objetos em um cenário 3D. Eles são essenciais para o cálculo da iluminação, pois determinam como a luz interage com a superfície. Em OpenGL, quando um objeto é transformado (escalado, rotacionado ou transladado), suas normais também sofrem transformações. Para assegurar que elas sejam corretamente ajustadas e continuem a representar vetores unitários (de comprimento 1), utiliza-se o comando glEnable(GL_NORMALIZE). A função glEnable(GL_COLOR_MATERIAL) permite que as cores dos materiais dos objetos reajam corretamente à iluminação.
glClearColor(0.1, 0.1, 0.1, 1.0): define a cor de fundo.
glLightfv(GL_LIGHT0, GL_POSITION, lightPos): estabelece a posição da fonte de luz.
*/

/* Função handleResize
glViewport(0, 0, w, h): ajusta a área de desenho para o tamanho atual da janela.
glMatrixMode(GL_PROJECTION) e glMatrixMode(GL_MODELVIEW): alternam entre modificar a matriz de projeção e a matriz de modelo/vista, respectivamente.
gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0): define a perspectiva da câmera com um campo de visão de 45 graus e um aspecto baseado no tamanho da janela.
*/

/* Função main
glutInit e funções relacionadas configuram a janela e o modo de exibição.
glutDisplayFunc(display) e glutIdleFunc(display): definem a função display como a função de callback para desenhar e atualizar a janela.
glutMainLoop(): inicia o loop de eventos da GLUT.
*/


