#include <GL/glut.h>

bool isBlack;

void drawWhiteBox(int x, int y) {
    glColor3f(0.0f, 0.0f, 0.0f); // Black border
    glBegin(GL_LINE_LOOP);
    glVertex2i(x, y);
    glVertex2i(x, y + 50);
    glVertex2i(x + 50, y + 50);
    glVertex2i(x + 50, y);
    glEnd();
}

void drawBlackBox(int x, int y) {
    glColor3f(0.0f, 0.0f, 0.0f); // Black fill
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x, y + 50);
    glVertex2i(x + 50, y + 50);
    glVertex2i(x + 50, y);
    glEnd();
}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    int startX = 50, startY = 50;

    for (int i = 0; i < 8; i++) {
        isBlack = (i % 2 == 0); // Alternate starting color for each row
        for (int j = 0; j < 8; j++) {
            int x = startX + j * 50;
            int y = startY + i * 50;

            if (isBlack)
                drawBlackBox(x, y);
            else
                drawWhiteBox(x, y);

            isBlack = !isBlack;
        }
    }

    glFlush();
}

void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0); // White background
    glColor3f(0.0f, 0.0f, 0.0f);      // Default color
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("8x8 Chess Board using Loop");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}
