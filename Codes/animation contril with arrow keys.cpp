#include <GL/gl.h>
#include <GL/glut.h>

GLfloat position = 0.0f;
GLfloat position2 = 0.0f;
GLfloat speed = 0.1f;

void update(int value)
{
/*  if(position > 1.0)
        position = -1.0f;

    position += speed;
	glutPostRedisplay();
*/


    if(position < -1.0)
            position = 1.0f;

    position -= speed;
	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}



void update2(int value)
{
/*
    if(position > 1.0)
        position = -1.0f;

    position += speed;
	glutPostRedisplay();
*/

    if(position > 1.0)
            position = -1.0f;

    position += speed;
	glutPostRedisplay();
	glutTimerFunc(100, update2, 0);
}


void init()
{
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

/*
void handleMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed += 0.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}

	glutPostRedisplay();
}*/

/*
void handleKeypress(unsigned char key, int x, int y)
{

	switch (key)
	{
        case 'a':
            speed = 0.0f;
            break;
        case 'w':
            speed = 0.1f;
            break;

        glutPostRedisplay();
	}
}
*/

void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
        //do something here
            glutTimerFunc(100, update2, 0);
            break;

        case GLUT_KEY_DOWN:
        //do something here
        // position2 -= speed;
        //position -= speed;
            glutTimerFunc(100, update, 0);
            break;

        case GLUT_KEY_LEFT:
            speed =0.0f;
            //do something here
            break;

        case GLUT_KEY_RIGHT:
            //do something here
            break;
    }
    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
        glTranslatef(position,position2, 0.0f);
        //glTranslatef(0.0f,position, 0.0f);
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.2f, -0.2f);
        glVertex2f( 0.2f, -0.2f);
        glVertex2f( 0.2f,  0.2f);
        glVertex2f(-0.2f,  0.2f);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.2f,-0.2f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.2f, 0.2f);
        glEnd();
    glPopMatrix();

   glFlush();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitWindowSize(320, 320);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Basic Animation");
   glutDisplayFunc(display);
   init();
   glutSpecialFunc(SpecialInput);
   //glutKeyboardFunc(handleKeypress);
   //glutMouseFunc(handleMouse);
   //glutTimerFunc(100, update, 0);
   glutMainLoop();
   return 0;
}
