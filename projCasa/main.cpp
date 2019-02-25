#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void reshape (int w, int h);
void EspecificaParametrosVisualizacao(void);
void AlteraTamanhoJanela(GLsizei w, GLsizei h);
void GerenciaMouse(int button, int state, int x, int y);
void PosicionaObservador(void);
void SpecialKeys(int key, int x, int y);

#define AZUL     0.0, 0.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0
#define AMARELO  1.0, 1.0, 0.0
#define VERDE    0.0, 1.0, 0.0
#define CYAN     1.0, 0.0, 1.0
#define LARANJA  0.8, 0.6, 0.1
#define ROSEO    0.7, 0.1, 0.6
#define CINZA    0.6, 0.6, 0.6
#define CANELA   0.82, 0.71, 0.55

GLfloat angle, fAspect;
GLdouble obsX=0, obsY=0, obsZ=200;


static GLfloat vertices[42]={
  -30.0, 0.0, 30.0,   // 0
  30.0, 0.0, 30.0 , // 1
  30.0, 30.0, 30.0 , // 2
  -30.0, 30.0, 30.0 , // 3
  -30.0, 0.0, 0.0, // 4
  30.0, 0.0, 0.0,   // 5
  30.0, 30.0, 0.0 , // 6
  -30.0, 30.0, 0.0 , // 7
  15.0, 50.0, 15.0 //8 Ponto max do teto

};

static GLfloat vertices_bkp[42]={
  -30.0,  30.0, 30.0, /* 0 */
  30.0, 30.0, 30.0, /* 1 */
  30.0, 30.0, 30.0, /* 2 */
  30.0,  0.0, 30.0, /* 3 */
  -30.0,   0.0, 30.0, /* 4 */
  -30.0,  30.0,  0.0, /* 5 */
  30.0, 30.0,  0.0, /* 6 */
  30.0,  0.0,  0.0, /* 7 */
  -30.0,   0.0,  0.0, /* 8 */
  30.0, 30.0, 30.0  /* 9 */

};

static GLubyte frenteIndices[]    = {0,1,2,3};
static GLubyte trasIndices[]      = {5,4,7,6};
static GLubyte esquerdaIndices[]  = {0,3,7,4};
static GLubyte direitaIndices[]   = {1,5,6,2};
static GLubyte topoIndices[]      = {3,2,6,7};
static GLubyte fundoIndices[]     = {0,4,5,1};


static GLubyte fundoTrian[]       = {6,7,8};
static GLubyte frenteTrian[]      = {3,2,8};
static GLubyte dirTrian[]         = {2,6,8};
static GLubyte esqTrian[]         = {7,3,8};


static int eixoy, eixox;
int largura, altura;

void gluLookAt( GLdouble eyex, GLdouble eyey, GLdouble eyez, GLdouble centerx, GLdouble centery, GLdouble centerz, GLdouble upx, GLdouble upy, GLdouble upz );

int main(int argc, char** argv){
  int i;
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (256, 256);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(GerenciaMouse);
  glutSpecialFunc(SpecialKeys);
  //glutReshapeFunc(reshape);
  glutReshapeFunc(AlteraTamanhoJanela);
  glutMainLoop();
  return 0;
}

void init(void){
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glOrtho (-50, 50, -50, 50, -50 , 50);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  angle=45;
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  largura=w;
  altura=h;
}

void display(void){
  glPushMatrix();
  glRotatef ((GLfloat) eixoy, 0.0, 1.0, 0.0);
  glRotatef ((GLfloat) eixox, 1.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, vertices);

  glColor3f (AZUL); /* frente */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, frenteIndices);

  glColor3f (VERMELHO); /* tras */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, trasIndices);

  glColor3f (AMARELO); /* esquerda */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, esquerdaIndices);

  glColor3f (VERDE); /* direita */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, direitaIndices);

  glColor3f (CYAN); /* topo */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, topoIndices);

  glColor3f (LARANJA); /* fundo */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, fundoIndices);

  glColor3f (CANELA); /* triang */
  glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, fundoTrian);

  glColor3f (CANELA); /* triang */
  glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, frenteTrian);

   glColor3f (CANELA); /* triang */
  glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, dirTrian);

  glColor3f (CANELA); /* triang */
  glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, esqTrian);

  glDisableClientState (GL_VERTEX_ARRAY);

  glPopMatrix();
  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
    exit(0);
    break;
  case 'a':
    //printf("%d, %d\n",x,y);
    break;
  case 'y':
    eixoy = (eixoy + 5) % 360;
    glutPostRedisplay();
    break;
  case 'Y':
    eixoy = (eixoy - 5) % 360;
    glutPostRedisplay();
    break;
  case 'x':
    eixox = (eixox + 5) % 360;
    glutPostRedisplay();
    break;
  case 'X':
    eixox = (eixox - 5) % 360;
    glutPostRedisplay();
    break;
  case 'p':
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) largura/(GLfloat) altura, 20.0, 120.0);
    gluLookAt(0, 0, -90, 0, 0, 0, 0, 1, 0);
    glutPostRedisplay();
    break;
  case 'o':
    glLoadIdentity();
    glOrtho (-50, 50, -50, 50, -50 , 50);
    glutPostRedisplay();
    break;

  }


}


// Função usada para especificar a posição do observador virtual
void PosicionaObservador(void)
{
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	// Especifica posição do observador e do alvo
    gluLookAt(0,80,200, 0,0,0, 0,1,0);
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
	gluPerspective(angle,fAspect,0.5,500);

	PosicionaObservador();
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
    glViewport(0, 0, w, h);

	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130) angle += 5;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

// Callback para gerenciar eventos do teclado para teclas especiais (F1, PgDn, entre outras)
void SpecialKeys(int key, int x, int y)
        {
		switch (key) {
			case GLUT_KEY_LEFT :
							obsX -=10;
							break;
			case GLUT_KEY_RIGHT :
							obsX +=10;
							break;
			case GLUT_KEY_UP :
							obsY +=10;
							break;
			case GLUT_KEY_DOWN :
							obsY -=10;
							break;

			case GLUT_KEY_HOME :
							obsZ +=10;
							break;
			case GLUT_KEY_END :
							obsZ -=10;
							break;
		}
		glLoadIdentity();
		gluLookAt(obsX,obsY,obsZ, 0,0,0, 0,1,0);
        	glutPostRedisplay();
        }
