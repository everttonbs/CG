#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

GLfloat xf, yf, win;
GLint view_w, view_h;

static int shoulder = 0, elbow = 0;

void init(void){
    //Cor de fundo
  glClearColor (0.0,0,0,0);
}


void display(void){

  glClear (GL_COLOR_BUFFER_BIT);
  glPushMatrix();

  /* origem posicionada */
  glTranslatef (-1.0, 0.0, 0.0);
  glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);

  /* origem posicionada no centro*/
  glTranslatef (1.0, 0.0, 0.0);
  glPushMatrix();
  //haste do catavento
  glLineWidth(5.0f);
  glBegin(GL_LINES);
        glColor3f(139, 69, 10);
        glVertex2i(1, 0);
        glVertex2i(1, -5);
      glEnd();
  glPopMatrix();


  /* origem posicionada  */
  glTranslatef (1.0, 0.0, 0.0);
  glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
  glTranslatef (1.0, 0.0, 0.0);

  glPushMatrix();
  glBegin(GL_TRIANGLES);
        glColor3f(2.0f, 1.0f, 1.0f);

        glVertex2f(-1, 0);
        glVertex2f(0, 2);
        glVertex2f(-2, 2);

        glColor3f(2.0f, 1.0f, 1.0f);
        glVertex2f(-1, 0);
        glVertex2f(-2, -2);
        glVertex2f(0, -2);

        glColor3f(1.0f, 2.0f, 1.0f);
        glVertex2f(-1, 0);
        glVertex2f(-3, 1);
        glVertex2f(-3, -1);

        glColor3f(2.0f, 1.0f, 1.0f);
        glVertex2f(-1, 0);
        glVertex2f(1, 1);
        glVertex2f(1, -1);

  glEnd();


  glPopMatrix();

  /*volta para o sistema de coordenadas original */
  glPopMatrix();
  glutSwapBuffers();
}

void reshape (int w, int h){

  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(130.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, 0.0, -5.0);
}


void keyboard (unsigned char key, int x, int y){
  switch (key) {
  case 'a':
    elbow = (elbow + 5) % 360;
    glutPostRedisplay();
    break;
  case 'd':
    elbow = (elbow - 5) % 360;
    glutPostRedisplay();
    break;
  case 27:
    exit(0);
    break;
  default:
    break;
  }

}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
      elbow = (elbow + 5) % 360;

    if (button == GLUT_RIGHT_BUTTON)
      elbow = (elbow - 5) % 360;

    glutPostRedisplay();


}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMouseFunc(GerenciaMouse);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
