
#include<cstdio>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

/*
#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
*/
GLint position = 80;
GLint speed =   5;

void aeroplaneMovement(int value) {

   if(position < -80)
        position = 80;

    position -= speed;

	glutPostRedisplay();



	glutTimerFunc(100, aeroplaneMovement, 0);
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

}
void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {
        case ' ':
            speed = 0.0f;
            break;

        case '2':
            speed = 1.0f;
            break;

        case '1':
            speed = 0.2f;
            break;
        glutPostRedisplay();
	}
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    ///Silo
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-40,-80);
    glVertex2f(-40,-40);
    glVertex2f(-45,-40);
    glVertex2f(-45,-80);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-60,-80);
    glVertex2f(-60,-40);
    glVertex2f(-65,-40);
    glVertex2f(-65,-80);
    glEnd();
    //Silo -- Top
    glBegin(GL_POLYGON);
    glVertex2f(-40,-40);
    glVertex2f(-40,-35);
    glVertex2f(-65,-35);
    glVertex2f(-65,-40);
    glEnd();



    ///Missile
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-50,-80);
    glVertex2f(-50,-50);
    glVertex2f(-55,-50);
    glVertex2f(-55,-80);
    glEnd();
    //missile -- top
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-50,-50);
    glVertex2f(-52.5,-45);
    glVertex2f(-55,-50);
    glEnd();


    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
    ///AeroPlane
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(25,20);
    glVertex2f(30,21);
    glVertex2f(30,23);
    glVertex2f(25,25);

    glVertex2f(5,25);
    glVertex2f(1,22);
    glVertex2f(5,20);
    glEnd();
    //Aeroplane -- rudder
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(30,22);
    glVertex2f(33,30);
    glVertex2f(30,30);
    glVertex2f(25,25);
    glEnd();
    //Aeroplane -- wing

    glPopMatrix();

    glFlush();

}
void reshape(int w, int h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int ortho = 80;
    gluOrtho2D(-ortho,ortho,-ortho,ortho);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

    int width = 1080;
    int height = 720;
    glutInitWindowSize(width, height);

    int x = 200;
    int y = 100;
    glutInitWindowPosition(x, y);

    glutCreateWindow("Basic Animation");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();

    glutTimerFunc(100, aeroplaneMovement, 0);
    //glutKeyboardFunc(handleKeypress);
    //glutMouseFunc(handleMouse);
    //glutTimerFunc(100, update, 0);
    glutMainLoop();
    return 0;
}
