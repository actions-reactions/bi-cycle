#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>


void wheel(int r, int xa, int ya, int sc)
{

    int x = 0, y, p;

    y = r;

    p = 1 - r;
    printf("p: %d\n", p);

    int i = 0;

    while (x < y)
    {
        if (p < 0)
        {

            x = x + 1;
            y = y;
            p = p + 2 * x + 1;
            i++;
            printf("p%d: %d\n", i, p);
            printf("x%d: %d, y%d: %d\n", i, x, i, y);
            printf("\n");

        }
        else
        {


            x = x + 1;
            y = y - 1;
            p = p + 2 * x - 2 * y + 1;
            i++;


            printf("p%d: %d\n", i, p);
            printf("x%d: %d, y%d: %d\n", i, x, i, y);
            printf("\n");



        }



        glBegin(GL_POINTS);


        glVertex2d((x+xa)/sc, (y + ya)/sc);



        glVertex2d((y+xa)/sc, (x + ya)/sc);



        glVertex2d((y+xa)/sc, (-x + ya)/sc);



        glVertex2d((x+xa)/sc, (-y + ya)/sc);



        glVertex2d((-x+xa)/sc, (-y + ya)/sc);



        glVertex2d((-y+xa)/sc, (-x + ya)/sc);



        glVertex2d((-y+xa)/sc, (x + ya)/sc);



        glVertex2d((-x+xa)/sc, (y + ya)/sc);


        glEnd();


    }

}






void display(void)
{
    /* clear all pixels */
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255, 0, 0);

    /* draw white polygon (rectangle) with corners at
     * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
     */



    glColor3ub(0, 0, 0);
    wheel(175,-400,0,1);

    glColor3ub(0, 0, 0);
    wheel(170,400,0,1);

    glColor3ub(0, 0, 0);
    wheel(15,-400,0,1);

    glColor3ub(0, 0, 0);
    wheel(15,400,0,1);



     glColor3ub(0, 0, 0);
     glBegin(GL_LINES);

     glVertex2d(-400,0);
     glVertex2d(-300, 250);

     glEnd();

     glColor3ub(0, 0, 0);
     glBegin(GL_LINES);


     glVertex2d(-300, 250);

     glVertex2d(-270,270);

     glEnd();



     glColor3ub(0, 0, 0);
     glBegin(GL_LINES);


     glVertex2d(-300, 250);

     glVertex2d(0,-30);

     glEnd();


     glColor3ub(0, 0, 0);
     glBegin(GL_LINES);

     glVertex2d(0,-30);

     glVertex2d(400, 0);

     glEnd();


     glColor3ub(0, 0, 0);
     glBegin(GL_LINES);

     glVertex2d(400, 0);

     glVertex2d(70,250);

     glEnd();



     glColor3ub(0, 0, 0);
     glBegin(GL_LINES);

     glVertex2d(70,250);

     glVertex2d(-300, 250);

     glEnd();


     glColor3ub(0, 0, 0);
     glBegin(GL_LINES);

     glVertex2d(0,-30);

     glVertex2d(80, 280);

     glEnd();


     glColor3ub(0, 0, 0);
     glBegin(GL_POLYGON);

     glVertex2d(30, 280);

     glVertex2d(120, 280);

     glVertex2d(120, 300);

     glVertex2d(30, 300);

     glEnd();





    /* don't wait!
     * start processing buffered OpenGL routines
     */
    glFlush();
}

void init(void)
{
    /* select clearing (background) color */
    glClearColor(1, 1, 1, 0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-600, 600, -600, 600);
}

/*
 * Declare initial window size, position, and display mode
 * (single buffer and RGBA). Open window with "hello"
 * in its title bar. Call initialization routines.
 * Register callback function to display graphics.
 * Enter main loop and process events.
 */
int main(int argc, char** argv)
{


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bi-cycle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
