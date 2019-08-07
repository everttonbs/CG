#include <GL/glut.h>
#include <stdlib.h>

static int year = 0;
static int day = 0;
static int luz = 0;


//GLfloat luzAmbiente[]={0.8f,0.8f,0.8f,1.0f};
GLfloat luzAmbiente[]={0.2f, 0.2f, 0.2f, 1.0f};
GLfloat luzDifusa[]={0.7f, 0.7f, 0.7f, 1.0f};
GLfloat luzEspecular[]={1.0f, 1.0f, 1.0f, 1.0f};
GLfloat posicaoLuz[]={0.0f, 50.0f, 50.0f, 1.0f};



GLfloat especularidade[]={1.0f, 1.0f, 1.0f, 1.0f};
GLint especMaterial = 60;



void init(void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);

glEnable(GL_LIGHT0);
glEnable(GL_LIGHTING);

glEnable(GL_COLOR_MATERIAL);
glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);


// Ativa o uso da luz ambiente
glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

// Define os parâmetros da luz de número 0
glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

// Define a reflectância do material
//glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
// Define a concentração do brilho
//glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

}

void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);


/**********/

/**********/


glColor3f(1.0, 1.0, 0.0);
glPushMatrix();//desenha o sol
glRotatef((GLfloat) year, 1.0, 0.0, 0.0);
glRotatef((GLfloat) day, 0.0, 0.0, 1.0);
//glutWireSphere(1.0, 20, 16);
glutSolidSphere(1.0,30,30);
glPopMatrix();

glColor3f(1.0, 0.0, 0.0);
//desenha um planeta
glPushMatrix();
	glRotatef((GLfloat) year, 0.0, 1.0, 0.0);
	glTranslatef(2.0, 0.0, 0.0);
	glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
	//glutWireSphere(0.2, 10, 8);
	glutSolidSphere(0.4,30,30);
glPopMatrix();


//desenha um planeta 2
glPushMatrix();
    glRotatef ((GLfloat) year, 0.0, -1.0, 0.0);//Movimento de rotação
    glTranslatef(2.5,0.0,0.0); //
    glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
    //glutWireSphere(0.2, 10, 8);
    glutSolidSphere(0.4,30,30);
    ///////////////////

    glColor3f(1.0, 1.0, 1.0);
glPushMatrix();//Lua 1
    	glRotatef ((GLfloat) year, 0.0, -1.0, 0.0);//Movimento de rotação
    	glTranslatef(0.25,0.5,0.0); //
    	glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
    	//glutWireSphere(0.12, 10, 8);
        glutSolidSphere(0.1,30,30);
 	glPopMatrix();

 	glPushMatrix();//Lua 2
    	glRotatef ((GLfloat) year, 1.0, 0.0, 0.0);//Movimento de rotação
      	glTranslatef(0.25,-0.5,0.0); //
    	glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
    	//glutWireSphere(0.12, 10, 8);
    	glutSolidSphere(0.1,30,30);
 	glPopMatrix();

   ///////////////////

  glPopMatrix();



glutSwapBuffers();


}

void reshape(int w, int h)
{
glViewport(0, 0, (GLsizei) w, (GLsizei) h);

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

gluPerspective(60.0, (GLfloat)w/(GLfloat)h, 1.0, 20.0);
gluLookAt(05.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //posição da camera

}

void keyboard(unsigned char key, int x, int y)
{
switch(key)
{
	case 'd':
	day = (day + 10) % 360;
	glutPostRedisplay();
	break;

	case 'D':
	day = (day - 10) % 360;
	glutPostRedisplay();
	break;

	case 'y':
	year = (year + 5)%360;
	glutPostRedisplay();
	break;

	case 'Y':
	year = (year - 5)%360;
	glutPostRedisplay();
	break;

	case 27:
	exit(0);
	break;

}

}


int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(100, 100);
glutCreateWindow("Rotação de Planetas");

init();

glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutKeyboardFunc(keyboard);
glutMainLoop();

return 0;
}
