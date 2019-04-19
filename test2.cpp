#include <gl/glut.h>
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>
#include <stdio.h>  
#include <vector>
#define DEG2RAD 3.14159/180.0
char title[] = "Cube";
GLfloat anglePyramid = 0.0f;  
GLfloat angleCube = 0.0f;     

int refreshMills = 15;        
 float deltaAngle = 0.0f;
int xOrigin = -1;

float angle=0.0;

float lx=0.0f,lz=-1.0f;
// XZ position of the camera
float x=0.0f,z=5.0f;
float r=0.0,lr=0.1f,llr=0.005f;
int q = 0;
typedef struct
{
double x,y,r1,r2;
}

SPHERE;

SPHERE sphere;





void createTriangle()
{
	glBegin(GL_TRIANGLES);
	glColor3f(1,0,0);
	glVertex3f(2.5,7.1,2.2);
	glVertex3f(1.2,-3.0,5.0);
	glVertex3f(0,0,0);
	glEnd();
}

void Dcircle()
{

	glBegin(GL_QUAD_STRIP);
	r=5.0;
	angle=0.0;
	deltaAngle=1.2;
	do
	{
		float x=(r*cos(angle));
		float y=2*(r*sin(angle));
		float z=0.0;
		glColor3f(1,0,0);
		glVertex3f(x,y,z);
		angle=angle+deltaAngle;
	}
	while (angle<360);
	glEnd();
}

void createcone()
{
	
	glBegin(GL_TRIANGLES);
	r=7.0;
	angle=0.0;
	deltaAngle=0.01;
	do
	{
		glColor3f(0,1,0);
		glVertex3f(r*cos(angle),15,(r*sin(angle)));
		glVertex3f(r*cos(angle+deltaAngle),15,(r*sin(angle+deltaAngle)));
		glColor3f(1,0,1);
		glVertex3f(0,15,0);
		angle=angle+deltaAngle;
	}
	while (angle<6.29);
	glEnd();
}

void createcylindar()
{
	glBegin(GL_QUAD_STRIP);
	r=5.0;
	angle=0.0;
	deltaAngle=0.01;
	do
	{
		glColor3f(1,0,0);
		glVertex3f(r*cos(angle),0,(r*sin(angle)));
		glVertex3f(r*cos(angle+deltaAngle),15,(r*sin(angle+deltaAngle)));
		angle=angle+deltaAngle;
	}
	while (angle<6.29);
	glEnd();
}

void Draw_Spheres (void)
{
	   glMatrixMode   (GL_MODELVIEW);
    glClear        (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    glTranslatef    (0.0, 0.0, -15.0);
 
    
 
    glColor3f (0.1, 0.2, 0.8);              
       glTranslatef    (1.5, 0.0, 0.0);
       glRotatef       (60.0, 1,0,0);
       glRotatef       (60.0, 0,0,1);
       glutSolidSphere (1.0, 20, 50);
    glPopMatrix ();
 
    glutSwapBuffers();
}
 


void createcube(float t)
{
	r =t+lr;
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex3f(r,r,r);
	glColor3f(1, 0, 0);
	glVertex3f(r,-r,r);
	glColor3f(1, 0, 0);
	glVertex3f(-r,-r,r);
	glColor3f(1, 0, 0);
	glVertex3f(-r,r,r);

	glColor3f(0, 1, 1);
	glVertex3f(-r,r,r);
	glColor3f(0, 1, 1);
	glVertex3f(-r,-r,r);
	glColor3f(0, 1, 1);
	glVertex3f(-r,-r,-r);
	glColor3f(0, 1, 1);
	glVertex3f(-r,r,-r);


	glColor3f(1, 0, 1);
	glVertex3f(r,-r,r);
	glColor3f(1, 0, 1);
	glVertex3f(-r,-r,r);
	glColor3f(1, 0, 1);
	glVertex3f(-r,-r,-r);
	glColor3f(1, 0, 1);
	glVertex3f(r,-r,-r);

	glColor3f(0, 1, 0);
	glVertex3f(r,r,r);
	glColor3f(0, 1, 0);
	glVertex3f(r,-r,r);
	glColor3f(0, 1, 0);
	glVertex3f(r,-r,-r);
	glColor3f(0, 1, 0);
	glVertex3f(r,r,-r);
	
	
	glColor3f(1, 1, 0);
	glVertex3f(r,r,-r);
	glColor3f(1, 1, 0);
	glVertex3f(r,-r,-r);
	glColor3f(1, 1, 0);
	glVertex3f(-r,-r,-r);
	glColor3f(1, 1, 0);
	glVertex3f(-r,r,-r);

	if ((lr < 0.0) || (lr > 7.0))
	{
		llr = -llr;
	}

	lr += llr;
	glEnd();

}






void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}




  

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
glMatrixMode(GL_MODELVIEW);     

  /* createcube(2.0); */
//createTriangle();  
//Draw_Spheres();

//Dcircle();
//OnRender();
//OnMouseMove();
//OnMouseDown();
//createcone();
createcylindar();
//createsphere();
glLoadIdentity();                 
   glTranslatef(0.0f, -3.0f, -50.0f);  
   gluLookAt(	x, 1.0f, z,
			x+lx, -2.0f,  z+lz,
			0.0f, 1.5f,  0.0f);
   glutSwapBuffers();


   
        
 
}




void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 2.0f;

	switch (key) {
		case GLUT_KEY_LEFT :
			angle -= 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT :
			angle += 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP :
			
			x += lx * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN :

			x -= lx * fraction;
			z -= lz * fraction;
			break;
	}
}

void myInit(void)
 {
    glClearColor(1.0,1.0,1.0,0.0);      
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void drawChecker(int size)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < 8 ; ++i) {
    for (j = 0; j < 8; ++j) {
        if((i + j)%2 == 0) 
            glColor3f( 0.4, 0.2, 0.6);
        else
            glColor3f( 0.2, 0.3, 0.4);
        glRecti(i*size, j*size, (i+1)*size, (j+1)*size);    
    }
}
    glFlush();
}

void checkerboard(void) {
    glClear(GL_COLOR_BUFFER_BIT);    
    drawChecker(32);

}


void timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char** argv) {
   
	 glutInit(&argc, argv);         
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(640,480);     
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Checker"); 
    glutDisplayFunc(checkerboard);     
    myInit();                   
    glutMainLoop();           

	/*glutInit(&argc, argv);           
   glutInitDisplayMode(GLUT_DOUBLE);
   glutInitWindowSize(640, 480);   
   glutInitWindowPosition(50, 50); 
   glutCreateWindow(title);          
   glutDisplayFunc(display);       
   glutReshapeFunc(reshape);      

	glutSpecialFunc(processSpecialKeys);
	glEnable(GL_DEPTH_TEST);
   
   initGL();                       
   glutTimerFunc(0, timer, 0);    
   glutMainLoop();                 
  
   return 1;*/
}
