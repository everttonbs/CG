#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

using namespace std;

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0.0, 500.0, 0.0, 400.0, -1.0, 1.0);



}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //glBegin(GL_POLYGON);
    //glBegin(GL_QUADS);
    glBegin(GL_QUAD_STRIP);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(145.0f, 10.0f);
        glVertex2f(155.0f, 10.0f);

        glVertex2f(145.0f, 150.0f);
        glVertex2f(155.0f, 150.0f);




    glEnd();

    glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(100.0f, 120.0f);
        glVertex2f(100.0f, 180.0f);
        glVertex2f(150.0f, 150.0f);

        glVertex2f(200.0f, 120.0f);
        glVertex2f(200.0f, 180.0f);
        glVertex2f(150.0f, 150.0f);

        glVertex2f(100.0f, 110.0f);
        glVertex2f(200.0f, 110.0f);
        glVertex2f(150.0f, 150.0f);

        glVertex2f(100.0f, 190.0f);
        glVertex2f(200.0f, 190.0f);
        glVertex2f(150.0f, 150.0f);

    glEnd();

    glFlush();
    glutSwapBuffers();


}


int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (200, 200);
  glutCreateWindow ("Flor");

  init();
  glutDisplayFunc(display);

  glutMainLoop();

  return 0;
}
