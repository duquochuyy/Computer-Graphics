#include "MouseAndKeyboard.h"
#include "Menu.h"
#include "Support.h"
#include "Matrix.h"

// chinh kich thuoc man hinh, toa do (0,0) o goc trai duoi
void myinit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

// set cac mau tuong ung
void setColor()
{
    W_Color = createColor(0, 255, 255, 255);
    B_Color = createColor(1, 0, 0, 0);
    G_Color = createColor(2, 0, 255, 0);
    R_Color = createColor(3, 255, 0, 0);
    Y_Color = createColor(4, 255, 255, 0);
    // mau khi chon hinh
    Selected_Color = createColor(5, 224, 224, 224);
}

// main: cac ham tao giao dien glut va ve
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(width, height);
    setColor();
    glutInitWindowPosition(100, 100);
    window = glutCreateWindow("20120101 - Lab 3");
    myinit();
    createMenu();
    // nen mau trang
    glClearColor(255.0, 255.0, 255.0, 0.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}