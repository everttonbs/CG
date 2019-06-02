#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <iostream>

static float y = 150.0f;
static float z = 150.0f;

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

    //Cadastrar os pontos no sentido anti-horário
    //glBegin(GL_POLYGON);
    glBegin(GL_QUADS);
    //glBegin(GL_QUAD_STRIP);
        glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(0.0f, 50.0f);
        glVertex2f(100.0f, 50.0f);
        glVertex2f(100.0f, y);
        glVertex2f(0.0f, y);

        glColor3f(1.0f, 1.0f, 0.0f);

        glVertex2f(120.0f, 50.0f);
        glVertex2f(220.0f, 50.0f);
        glVertex2f(220.0f, y);
        glVertex2f(120.0f, y);


        glColor3f(1.0f, 0.0f, 0.0f);

        glVertex2f(240.0f, 50.0f);
        glVertex2f(340.0f, 50.0f);
        glVertex2f(340.0f, y);
        glVertex2f(240.0f, y);

        glColor3f(0.0f, 1.0f, 0.0f);

        glVertex2f(360.0f, 50.0f);
        glVertex2f(460.0f, 50.0f);
        glVertex2f(460.0f, y);
        glVertex2f(360.0f, y);

    glEnd();

    glFlush();
    glutSwapBuffers();

}

// Função callback chamada para gerenciar eventos de teclado
void GerenciaTeclado(unsigned char key, int x1, int y1)
{
    switch(key)
    {
    case 'o':
        y = 250.0f;
        break;

    case 'p':
        y = 150.0f;
        break;

    }

    glutPostRedisplay();

}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (200, 200);
    glutCreateWindow ("Ola_Torcida");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(GerenciaTeclado);

    glutMainLoop();

    return 0;
}

