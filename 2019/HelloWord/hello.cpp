// PrimeiroPrograma.c - Isabel H. Manssour
// Um programa OpenGL simples que abre uma janela GLUT
// Este código está baseado no Simple.c, exemplo
// disponível no livro "OpenGL SuperBible",
// 2nd Edition, de Richard S. e Wright Jr.

#include <gl/glut.h>
#include <string.h>
#include <stdio.h>

int time_casa = 1;
int time_visitante = 1;
char texto[30];
GLfloat win;

static float x = 50.0f;
static float y = 50.0f;
static float z = 15.0f;

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0.0, 500.0, 0.0, 400.0, -1.0, 1.0);
    win = 150.0f;

}


// Desenha um texto na janela GLUT
void DesenhaPlacar(char *string)
{
  	glPushMatrix();
        // Posição no universo onde o texto será colocado
        //glRasterPos2f(-0.90,0.8);
        glRasterPos2f(0.0,350.0);
        //glRasterPos2f(0,0-(0*0.08));
        //glRasterPos2f(0,0);
        // Exibe caracter a caracter
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string++);
	glPopMatrix();
}
// Função callback chamada para fazer o desenho
void Desenha(void)
{
	//Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x, y + z);
        glVertex2f(x, y);
        glVertex2f(x + z, y);
        glVertex2f(x + z , y + z);
    glEnd();

    sprintf(texto, "Placar\n IC %d x %d VISITANTES", time_casa, time_visitante);

	DesenhaPlacar(texto);

	//Executa os comandos OpenGL
	glFlush();
}

// Função callback chamada para gerenciar eventos de teclado
void GerenciaTeclado(unsigned char key, int x1, int y1)
{

    switch(key)
    {
        //case GLUT_KEY_RIGHT:
        case 'd':
            x = x + 10;
            glutPostRedisplay();
            break;

        //case GLUT_KEY_LEFT:
        case 'a':
            x = x - 10;
            glutPostRedisplay();
            break;

        //case GLUT_KEY_UP:
        case 'w':
            y = y + 10;
            glutPostRedisplay();
            break;

        //case GLUT_KEY_DOWN:
        case 's':
            y = y - 10;
            if(y < 0)
            {
                time_casa = time_casa + 1;
                x = 150.0f;
                y = 150.0f;
            }

            glutPostRedisplay();
            break;


    }
    glutPostRedisplay();

}

// Programa Principal
int main(int argc, char** argv){

    glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Teste placar");
	glutDisplayFunc(Desenha);
	glutKeyboardFunc(GerenciaTeclado);
	init();
	glutMainLoop();
}



