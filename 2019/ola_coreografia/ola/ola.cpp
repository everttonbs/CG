#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <iostream>

static float x = 75.0f;
static float y = 15.0f;
static float y0 = -15.0f;
static float y1 = 15.0f;
static float y2 = 15.0f;
static float y3 = 15.0f;
static float y4 = 15.0f;
static float y5 = 15.0f;
static float y6 = 15.0f;
static float y7 = 15.0f;
static float z = 15.0f;

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
    glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x, y1 + z);
        glVertex2f(x, y1);
        glVertex2f(x + z, y1);
        glVertex2f(x + z , y1 + z);


        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex2f(x + 50, y2 + z);
        glVertex2f(x + 50, y2);
        glVertex2f(x + 50 + z, y2);
        glVertex2f(x + 50 + z , y2 + z);


        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(x + 100, y3 + z);
        glVertex2f(x + 100, y3);
        glVertex2f(x + 100 + z, y3);
        glVertex2f(x + 100 + z , y3 + z);


        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(x + 150, y4 + z);
        glVertex2f(x + 150, y4);
        glVertex2f(x + 150 + z, y4);
        glVertex2f(x + 150 + z , y4 + z);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(x + 200, y5 + z);
        glVertex2f(x + 200, y5);
        glVertex2f(x + 200 + z, y5);
        glVertex2f(x + 200 + z , y5 + z);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(x + 250, y6 + z);
        glVertex2f(x + 250, y6);
        glVertex2f(x + 250 + z, y6);
        glVertex2f(x + 250 + z , y6 + z);

        glColor3f(1.0f, 1.0f, 0.50f);
        glVertex2f(x + 300, y7 + z);
        glVertex2f(x + 300, y7);
        glVertex2f(x + 300 + z, y7);
        glVertex2f(x + 300 + z , y7 + z);



    glEnd();

    glFlush();
    glutSwapBuffers();

}

void Up(int value)
{
    y0 += 5;

    if(y0 > 0 && y1 < 200 && y0<200)
        y1 += 5;
    else
        y1 = y;

    if(y0 > 50 && y2 < 200 && y0<250)
        y2+= 5;
    else
        y2 = y;

    if(y0 > 100 && y3 < 200 && y0<300)
        y3+=5;
    else
        y3 = y;

    if(y0 > 150 && y4 && y0<350)
        y4+= 5;
    else
        y4 = y;

    if(y0 > 200 && y5 < 200 && y0<400)
        y5+= 5;
    else
        y5 = y;

    if(y0 > 250 && y6 < 200 && y0<450)
        y6+= 5;
    else
        y6 = y;

    if(y0 > 300 && y7 < 200 && y0<500)
        y7+= 5;

    else
        y7 = y;



    glutPostRedisplay();
    glutTimerFunc(30, Up, 1);





}

// Função callback chamada para gerenciar eventos de teclado
void GerenciaTeclado(unsigned char key, int x1, int y1)
{
    switch(key)
    {
    case 'o':
        //y = 250.0f;
        //x += 5;
        //y += 5;
        y0 = 0;
        glutTimerFunc(30, Up, 1);


        break;

    case 'p':
        y -= 5;
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

    //glutTimerFunc(33, Timer, 1);

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(GerenciaTeclado);

    glutMainLoop();

    return 0;
}



