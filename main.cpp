
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

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    //Silo
    glBegin(GL_POLYGON);
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

    //glutKeyboardFunc(handleKeypress);
    //glutMouseFunc(handleMouse);
    //glutTimerFunc(100, update, 0);
    glutMainLoop();
    return 0;
}
