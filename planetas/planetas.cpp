#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

static int year = 0, day = 0;


void init(void){
  glClearColor (0.0,0,0,0);
}


void display(void){

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);

  //cria sol
	glPushMatrix();
		glRotatef ((GLfloat) year, 1.0, 0.0, 0.0);
		glRotatef ((GLfloat) day, 0.0, 0.0, 1.0);
		glutWireSphere(1.0,20,16);
	glPopMatrix();

  //cria planeta 1
	glPushMatrix();
		glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
		glTranslatef(2.0,0.0,0.0);
		glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
		glutWireSphere(0.2,10,8);
	glPopMatrix();

//cria planeta 2

  glPushMatrix();
    glRotatef ((GLfloat) year, 0.0, -1.0, 0.0);//Movimento de rotação
    glTranslatef(2.5,0.0,0.0); //
    glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
    glutWireSphere(0.2, 10, 8);
  glPopMatrix();



	glutSwapBuffers();


}

void reshape (int w, int h){

  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity ();
  gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
  gluLookAt(0.0, 0.0,5.0,0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

}


void keyboard (unsigned char key, int x, int y){
  switch (key) {
  case 'd':
    day = (day + 10) % 360;
    glutPostRedisplay();
    break;
  case 'D':
    day = (day- 10) % 360;
    glutPostRedisplay();
    break;
  case 'y':
    year = (year + 5) % 360;
    glutPostRedisplay();
    break;
  case 'Y':
    year = (year- 5) % 360;
    glutPostRedisplay();
    break;
  case 27:
    exit(0);
    break;
  default:
    break;
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (600, 600);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);

  init ();

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
