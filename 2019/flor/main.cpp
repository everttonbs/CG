#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <iostream>

static float x = 0.0f, y = 1.0f, z = 0.0f, a = 1.0f, b = 0.0f, c = 0.0f, d = 0.0f, e = 0.0f, f = 1.0f, g = 1.0f, h = 1.0f, i = 0.0f;
static float aux1, aux2, aux3;
using namespace std;

void right()
{
    aux1 = g; aux2 = h; aux3 = i;
    g = d; h = e; i = f;
    d = a; e = b; f = c;
    a = x; b = y; c = z;
    x = aux1; y = aux2; z = aux3;
}
void left()
{
    aux1 = x; aux2 = y; aux3 = z;
    x = a; y = b; z = c;
    a = d; b = e; c = f;
    d = g; e = h; f = i;
    g = aux1; h = aux2; i = aux3;

}

void GerenciadorMouse(int button, int state, int x1, int y1)
{
    // O state é fundamental no click, caso contrário é contado 2x
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        left();
        //cout << "Hello\n"; //Verifica quantas vezes é pressionado o botão

    }

    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        right();
    }


}

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
        glVertex2f(145.0f, 50.0f);
        glVertex2f(155.0f, 50.0f);

        glVertex2f(145.0f, 150.0f);
        glVertex2f(155.0f, 150.0f);

    glEnd();


    glBegin(GL_TRIANGLES);

        glColor3f(x, y, z); //0, 1, 0
        glVertex2f(110.0f, 135.0f);
        glVertex2f(110.0f, 165.0f);
        glVertex2f(150.0f, 150.0f);

        glColor3f(a, b, c); //1, 0, 0
        glVertex2f(135.0f, 190.0f);
        glVertex2f(165.0f, 190.0f);
        glVertex2f(150.0f, 150.0f);

        glColor3f(d, e, f); //0, 0, 1
        glVertex2f(190.0f, 135.0f);
        glVertex2f(190.0f, 165.0f);
        glVertex2f(150.0f, 150.0f);

        glColor3f(g, h, i); //1, 1, 0
        glVertex2f(135.0f, 110.0f);
        glVertex2f(165.0f, 110.0f);
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

    glutMouseFunc(GerenciadorMouse);

    glutMainLoop();

    return 0;
}


