#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void reshape (int w, int h);

#define AZUL     0.0, 0.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0
#define AMARELO  1.0, 1.0, 0.0
#define VERDE    0.0, 1.0, 0.0
#define CYAN     1.0, 0.0, 1.0
#define LARANJA  0.8, 0.6, 0.1
#define ROSEO    0.7, 0.1, 0.6
#define CINZA    0.6, 0.6, 0.6
#define CANELA   0.82, 0.71, 0.55


static GLfloat vertices[42]={
  0.0, 0.0, 30.0,   // 0
  30.0, 0.0, 30.0 , // 1
  30.0, 30.0, 30.0 , // 2
  0.0, 30.0, 30.0 , // 3
  0.0, 0.0, 0.0, // 4
  30.0, 0.0, 0.0,   // 5
  30.0, 30.0, 0.0 , // 6
  0.0, 30.0, 0.0 , // 7
  15.0, 45.0, 15.0 //8
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
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}

void init(void){
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glOrtho (-50, 50, -50, 50, -50 , 50);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
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
