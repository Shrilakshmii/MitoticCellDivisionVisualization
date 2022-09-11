#include <stdio.h>
#include<windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glu.h>
#include <stdbool.h>
#include<math.h>

int i;
int counter=1;
float tx=0;
float ty=0;
float tx1=-50;
float ty1=20;
float tx2=200;
float ty2=20;
float tx3=400;
float ty3=0;
float tx4=-280;
float ty4=110;
float tx5=-280;
float ty5=110;
float tx6=50;
float ty6=110;
float tx7=50;
float ty7=110;
float tx8=340;
float ty8=110;
float tx9=340;
float ty9=110;
float tx10=640;
float ty10=110;
float tx11=640;
float ty11=110;
float spin=0;

float t1=0;
float t2=0;
float t11=650;
float t12=0;
float t1n=450;
float t1m=-250;

#ifndef PI
#define PI 3.14159265358979323846
#endif

bool prophase=false;
bool metaphase=false;
bool anaphase=false;

//void gluDisk( GLUquadric *qobj, GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint loops);
//void gluCylinder(GLUquadric* quad, GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks);

enum view {INTRO, MENU, PHASES,MITOSIS,GROWTH,PMAT,INTERPHASE,LAST};
enum view viewPage=INTRO; // initial value
bool keyStates[256] = { false };

//TO DRAW TEXT
void displayRasterText(float x, float y,const char* text)
{
        glRasterPos2f(x, y);
        for (i=0;i<strlen(text);i++)
        {
                glutBitmapCharacter(GLUT_BITMAP_9_BY_15,text[i]);
        }
}

void displayRasterText1(float x, float y, const char* text)
{
        glRasterPos2f(x, y);
        for (i=0;i<strlen(text);i++)
        {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
        }
}

void DrawCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int lineAmount = 100; //# of triangles used to draw circle
	
	GLfloat twicePi = 2.0f * PI;
	
	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= lineAmount;i++) { 
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)), 
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}

//init function
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-800,800,-800,800,-800,2000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//introscreen
void introScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(1.0, 0, 0);
    displayRasterText(-130, 300, "A MINI PROJECT ON ");


    glColor3f(0.2, 0.5, 1.0);
    displayRasterText(-170, 155, "Mitotic Cell Division");


    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-80, 100, "CREATED BY");

    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-130, -200,  " SHRILAKSHMI K");
    

    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-150, -450,  "PRESS ENTER TO START");


    glFlush();
    glutSwapBuffers();
}
void line1()
{
	glPushMatrix();
	glBegin(GL_LINES);
		glVertex2f(150,150);
		glVertex2f(-100,100);
	glEnd();
	glPopMatrix();
}
void line2()
{
	glPushMatrix();
	glBegin(GL_LINES);
		glVertex2f(60,-50);
		glVertex2f(150,150);
	glEnd();
	glPopMatrix();
}

void line3()
{
	glPushMatrix();
	glBegin(GL_LINES);
		glVertex2f(50,50);
		glVertex2f(-50,200);
	glEnd();
	glPopMatrix();
}
void line4()
{
	glPushMatrix();
	glBegin(GL_LINES);
		glVertex2f(-150,-50);
		glVertex2f(50,50);
	glEnd();
	glPopMatrix();
}
void line5()
{
	glPushMatrix();
	glBegin(GL_LINES);
		glVertex2f(50,50);
		glVertex2f(80,300);
	glEnd();
	glPopMatrix();
}
void line6()
{
	glPushMatrix();
	glBegin(GL_LINES);
		glVertex2f(-150,100);
		glVertex2f(50,50);
	glEnd();
	glPopMatrix();
}


void arrow()
{
	glColor3f(1,1,0);
	glPushMatrix();
	glTranslatef(-450,201,0);
	line1();
	glPopMatrix();
	
	glColor3f(1,1,0);
	glPushMatrix();
	glTranslatef(-450,200,0);
	line2();
	glPopMatrix();
}

void arrow_second()
{
	glColor3f(1,1,0);
	glPushMatrix();
	glTranslatef(-350,201,0);
	line3();
	glPopMatrix();
	
	glColor3f(1,1,0);
	glPushMatrix();
	glTranslatef(-350,200,0);
	line4();
	glPopMatrix();
}
void arrow_third()
{
	glColor3f(1,1,0);
	glPushMatrix();
	glTranslatef(-50,201,0);
	line5();
	glPopMatrix();
	
	glColor3f(1,1,0);
	glPushMatrix();
	glTranslatef(-50,200,0);
	line6();
	glPopMatrix();
}
void arrow1()
{
	glColor3f(1,1,0);
	glPushMatrix();
	glTranslatef(t1,t2,0);
	arrow();
	glPopMatrix();
}

void arrow2()
{
	glColor3f(1,1,0);
	glPushMatrix();
	glTranslatef(t11,t12,0);
	arrow_second();
	glPopMatrix();
}
void arrow3()
{
	glColor3f(1,1,0);
	glPushMatrix();
	glTranslatef(t1n,t1m,0);
	arrow_third();
	glPopMatrix();
}


void Phases()
{
	glColor3f(1.0, 1.0, 1.0);
    displayRasterText1(-200, 100, "MITOTIC CELL DIVISION");
		
    
    DrawCircle(50,50,600);
    
    glPushMatrix();
	arrow1();
	glPopMatrix();
	
	glPushMatrix();
	arrow2();
	glPopMatrix();
	
	glPushMatrix();
	arrow3();
	glPopMatrix();
	
	glColor3f(1.0, 1.0, 0);
    displayRasterText(500, 450, "INTERPHASE");
    
    glColor3f(1.0, 1.0, 0);
    displayRasterText(-280, 640, "CYTOKINESIS");
    
    glColor3f(1.0, 1.0, 0);
    displayRasterText(-280, -560, "MITOSIS");
    
    glColor3f(1.0, 0, 0);
    displayRasterText(-300,50, "This cell division has mainly three parts");
    
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(450, -660, "PRESS 'q' or 'Q'");

}
void arrowTranslation()
{
	t1=t1+0.016;
	t2=t2+0.07;
	
	if(t1>-50 && t2>150)
	{
		t1=-50;
		t2=150;
	}
	
	t11=t11+0.03;
	t12=t12+0.18;
	
	if(t11>660 && t12>315)
	{
		t11=660;
		t12=315;
	}
	glutPostRedisplay();
	
	t1n=t1n+0.08;
	t1m=t1m+0.048;
	
	if(t1n>645 && t1m>-300)
	{
		t1n=645;
		t1m=-300;
	}
	glutPostRedisplay();	
}
void Mitosis()
{
	glLoadIdentity();
	glTranslatef(0,400,0);	
	glColor3f(0.560784,0.560784, 0.737255);
	GLUquadric *cell2= gluNewQuadric();
	gluDisk(cell2,0.0,180.0,20,1);
	
	glLoadIdentity();
	glTranslatef(0,400,0);	
	glColor3f(1,1, 1);
	GLUquadric *cell3= gluNewQuadric();
	gluDisk(cell3,0.0,80.0,20,1);
	
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(-80,-200);
		glVertex2f(-250,-550);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(80,-200);
		glVertex2f(250,-550);
	glEnd();
	
	glLoadIdentity();
	glTranslatef(-250,-350,0);	
	glColor3f(0.560784,0.560784, 0.737255);
	GLUquadric *cell4= gluNewQuadric();
	gluDisk(cell4,0.0,180.0,20,1);
	
	glLoadIdentity();
	glTranslatef(-250,-350,0);	
	glColor3f(1,1, 1);
	GLUquadric *cell5= gluNewQuadric();
	gluDisk(cell3,0.0,80.0,20,1);
	
	glLoadIdentity();
	glTranslatef(250,-350,0);	
	glColor3f(0.560784,0.560784, 0.737255);
	GLUquadric *cell6= gluNewQuadric();
	gluDisk(cell6,0.0,180.0,20,1);
	
	glLoadIdentity();
	glTranslatef(250,-350,0);	
	glColor3f(1,1, 1);
	GLUquadric *cell7= gluNewQuadric();
	gluDisk(cell7,0.0,80.0,20,1);
	
	glColor3f(1.0, 1.0, 0);
    displayRasterText1(-350,1000, "MITOSIS");
    
	glColor3f(0,1,1);
	displayRasterText(-730,-220,"Diploid Daughter Cell-1");
	
	glColor3f(0,1,1);
	displayRasterText(-150,-220,"Diploid Daughter Cell-2");
	
	glColor3f(0,1,1);
	glBegin(GL_LINES);
		glVertex2f(100,700);
		glVertex2f(-50,700);
	glEnd();
	
	glColor3f(0,1,1);
	displayRasterText(120,690,"Diploid Parent Cell");
	
	glLoadIdentity();
	glTranslatef(-20,430,0);
	glRotatef(150,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_3_inside1= gluNewQuadric();
	gluCylinder(cell_3_inside1, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(-30,400,0);
	glRotatef(270,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_3_inside2= gluNewQuadric();
	gluCylinder(cell_3_inside2, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(-5,420,0);
	glRotatef(60,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_3_inside3= gluNewQuadric();
	gluCylinder(cell_3_inside3, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(-250,-370,0);
	glRotatef(150,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_5_inside1= gluNewQuadric();
	gluCylinder(cell_5_inside1, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(-260,-370,0);
	glRotatef(270,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_5_inside2= gluNewQuadric();
	gluCylinder(cell_5_inside2, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(-280,-390,0);
	glRotatef(60,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_5_inside3= gluNewQuadric();
	gluCylinder(cell_5_inside3, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(270,-370,0);
	glRotatef(150,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_7_inside1= gluNewQuadric();
	gluCylinder(cell_7_inside1, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(260,-360,0);
	glRotatef(270,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_7_inside2= gluNewQuadric();
	gluCylinder(cell_7_inside2, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(225,-370,0);
	glRotatef(60,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_7_inside3= gluNewQuadric();
	gluCylinder(cell_7_inside3, 5,10,55,10,1);
	
	glColor3f(1,1,1);
	displayRasterText(0,-450,"PRESS 'W or w' KEY");
}
void Growth()
{
	glLoadIdentity();	
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(-625,-500);
	glVertex2f(-600,-500);
	glVertex2f(-600,380);
	glVertex2f(-625,380);
	glEnd();
	
	glLoadIdentity();	
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(-625,380);
	glVertex2f(15,380);
	glVertex2f(15,355);
	glVertex2f(-625,355);
	glEnd();
	
	glLoadIdentity();	
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(15,380);
	glVertex2f(15,-500);
	glVertex2f(-10,-500);
	glVertex2f(-10,380);
	glEnd();
	
	glLoadIdentity();	
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(15,-500);
	glVertex2f(15,-300);
	glVertex2f(-625,-300);
	glVertex2f(-625,-500);
	glEnd();
	
	glLoadIdentity();
	glTranslatef(-500,180,0);	
	glColor3f(1,1,1);
	GLUquadric *cell_ear1= gluNewQuadric();
	gluDisk(cell_ear1,0.0,80.0,20,1);
	
	glLoadIdentity();
	glTranslatef(-100,180,0);	
	glColor3f(1,1,1);
	GLUquadric *cell_ear2= gluNewQuadric();
	gluDisk(cell_ear2,0.0,80.0,20,1);
	
	glLoadIdentity();
	glTranslatef(-500,180,0);	
	glColor3f(0,0,0);
	GLUquadric *cell_ear_in1= gluNewQuadric();
	gluDisk(cell_ear_in1,0.0,40.0,20,1);
	
	glLoadIdentity();
	glTranslatef(-100,180,0);	
	glColor3f(0,0,0);
	GLUquadric *cell_ear_in2= gluNewQuadric();
	gluDisk(cell_ear_in2,0.0,40.0,20,1);
	
	glLoadIdentity();
	glTranslatef(-300,0,0);	
	glColor3f(1,1,1);
	GLUquadric *cell= gluNewQuadric();
	gluDisk(cell,0.0,250.0,20,1);
	
	glLoadIdentity();
	glTranslatef(-50,-30,0);
	glColor3f(0,0,0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-450,20);
	glVertex2f(-330,160);
	glVertex2f(-290,-10);
	glEnd();
	
	glLoadIdentity();
	glTranslatef(-20,-30,0);
	glColor3f(0,0,0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-250,-10);
	glVertex2f(-200,160);
	glVertex2f(-90,20);
	glEnd();
	
	glColor3f(1,1,1);
	DrawCircle(-180,50,20);
	
	glColor3f(1,1,1);
	DrawCircle(-380,50,20);
	
	glLoadIdentity();
	glTranslatef(-400,20,0);	
	glColor3f(1,1,1);
	GLUquadric *celleye= gluNewQuadric();
	gluDisk(celleye,0.0,5.0,20,1);
	
	glLoadIdentity();
	glTranslatef(-200,20,0);	
	glColor3f(1,1,1);
	GLUquadric *celleye1= gluNewQuadric();
	gluDisk(celleye1,0.0,5.0,20,1);
	
	glLoadIdentity();
	glTranslatef(-300,0,0);	
	glColor3f(0,0,0);
	GLUquadric *cell_nose= gluNewQuadric();
	gluDisk(cell_nose,0.0,25.0,20,1);
	
	glLoadIdentity();
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(-300,0);
	glVertex2f(-300,-100);
	glEnd();
	
	glLoadIdentity();
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(-300,-100);
	glVertex2f(-350,-70);
	glEnd();
	
	glLoadIdentity();
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(-300,-100);
	glVertex2f(-250,-70);
	glEnd();
	
	glLoadIdentity();
	glTranslatef(-400,-70,0);	
	glColor3f(0.737255,0.560784,0.560784);
	GLUquadric *cell_cheek1= gluNewQuadric();
	gluDisk(cell_cheek1,0.0,15.0,20,1);
	
	glLoadIdentity();
	glTranslatef(-200,-70,0);	
	glColor3f(0.737255,0.560784,0.560784);
	GLUquadric *cell_cheek2= gluNewQuadric();
	gluDisk(cell_cheek2,0.0,15.0,20,1);	
	
	glLoadIdentity();
	glColor3f(0,1,0);
	glBegin(GL_LINES);
	glVertex2f(40,0);
	glVertex2f(100,0);
	glEnd();
	
	glLoadIdentity();
	glColor3f(0,1,0);
	glBegin(GL_LINES);
	glVertex2f(100,0);
	glVertex2f(60,-50);
	glEnd();
	
	glLoadIdentity();
	glColor3f(0,1,0);
	glBegin(GL_LINES);
	glVertex2f(100,0);
	glVertex2f(60,50);
	glEnd();
	
	//other side bear
	glLoadIdentity();
	glTranslatef(650,170,0);	
	glColor3f(1,1,1);
	GLUquadric *cell_bear_ear1= gluNewQuadric();
	gluDisk(cell_bear_ear1,0.0,80.0,20,1);
	
	glLoadIdentity();
	glTranslatef(250,170,0);	
	glColor3f(1,1,1);
	GLUquadric *cell_bear_ear2= gluNewQuadric();
	gluDisk(cell_bear_ear2,0.0,80.0,20,1);
	
	glLoadIdentity();
	glTranslatef(650,180,0);	
	glColor3f(0,0,0);
	GLUquadric *cell_bear_ear_in1= gluNewQuadric();
	gluDisk(cell_bear_ear_in1,0.0,40.0,20,1);
	
	glLoadIdentity();
	glTranslatef(250,180,0);	
	glColor3f(0,0,0);
	GLUquadric *cell_bear_ear_in2= gluNewQuadric();
	gluDisk(cell_bear_ear_in2,0.0,40.0,20,1);
	
	glLoadIdentity();
	glTranslatef(450,0,0);	
	glColor3f(1,1,1);
	GLUquadric *cell_bear= gluNewQuadric();
	gluDisk(cell_bear,0.0,250.0,20,1);
	
	glLoadIdentity();
	glTranslatef(700,-30,0);
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(-450,20);
	glVertex2f(-330,160);
	glVertex2f(-290,-10);
	glVertex2f(-370,-75);
	glEnd();
	
	glLoadIdentity();
	glTranslatef(725,-30,0);
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(-250,-10);
	glVertex2f(-210,160);
	glVertex2f(-90,20);
	glVertex2f(-175,-75);
	glEnd();
	
	glLoadIdentity();
	glTranslatef(530,20,0);	
	glColor3f(1,1,1);
	GLUquadric *celleye2= gluNewQuadric();
	gluDisk(celleye2,0.0,5.0,20,1);
	
	glLoadIdentity();
	glTranslatef(360,20,0);	
	glColor3f(1,1,1);
	GLUquadric *celleye3= gluNewQuadric();
	gluDisk(celleye3,0.0,5.0,20,1);
	
	glLoadIdentity();
	glTranslatef(440,20,0);	
	glColor3f(0,0,0);
	GLUquadric *cell_nose1= gluNewQuadric();
	gluDisk(cell_nose1,0.0,30.0,20,1);
	
	glLoadIdentity();
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(440,0);
	glVertex2f(440,-120);
	glEnd();
	
	glLoadIdentity();
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(440,-120);
	glVertex2f(400,-70);
	glEnd();
	
	glLoadIdentity();
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(440,-120);
	glVertex2f(480,-70);
	glEnd();
	
	glLoadIdentity();
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(490,-80);
	glVertex2f(520,-100);
	glEnd();
	
	glLoadIdentity();
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(390,-80);
	glVertex2f(360,-100);
	glEnd();
	
	glLoadIdentity();	
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(150,-500);
	glVertex2f(125,-500);
	glVertex2f(125,380);
	glVertex2f(150,380);
	glEnd();
	
	glLoadIdentity();	
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(150,380);
	glVertex2f(770,380);
	glVertex2f(770,355);
	glVertex2f(150,355);
	glEnd();
	
	glLoadIdentity();	
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(770,380);
	glVertex2f(770,-500);
	glVertex2f(745,-500);
	glVertex2f(745,380);
	glEnd();
	
	glLoadIdentity();	
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(770,-500);
	glVertex2f(770,-300);
	glVertex2f(150,-300);
	glVertex2f(150,-500);
	glEnd();
	
	glColor3f(1,1,1);
	displayRasterText(400,-630,"PRESS 'E' or e' KEY");
	
	glColor3f(1,1,1);
	displayRasterText1(-700,700,"PURPOSE OF MITOSIS");
	
	glColor3f(1,1,1);
	displayRasterText(-600,630,"Mitosis helps in");
	
	glColor3f(0,1,1);
	displayRasterText(-600,580,"1. Growth");
	
	glColor3f(0,1,1);
	displayRasterText(-600,530,"2. Regeneration");
	
	glColor3f(0,1,1);
	displayRasterText(-600,480,"3. Repair");
}
void Mitosis_phases()
{
	glLineWidth(5);
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(-600,0);
		glVertex2f(600,0);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(500,200);
		glVertex2f(600,0);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(500,-200);
		glVertex2f(600,0);
	glEnd();
	
	//partition lines
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(-300,200);
		glVertex2f(-300,-200);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(-80,200);
		glVertex2f(-80,-200);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(180,200);
		glVertex2f(180,-200);
	glEnd();
	
	glColor3f(1,1,1);
	displayRasterText1(250,-600,"PRESS 'R' or 'r' KEY");
	
	glColor3f(1,1,1);
	displayRasterText1(-700,700,"PHASES IN MITOSIS");
	
	glColor3f(0,1,1);
	displayRasterText1(-600,550,"1. Prophase");
	
	glColor3f(0,1,1);
	displayRasterText1(1-600,470,"2. Metaphase");
	
	glColor3f(0,1,1);
	displayRasterText1(-600,400,"3. Anaphase");
	
	glColor3f(0,1,1);
	displayRasterText1(-600,330,"4. Telophase");
	
	glColor3f(1,1,0);
	displayRasterText(-500,20,"PROPHASE");
	
	glColor3f(1,1,0);
	displayRasterText(-270,20,"METAPHASE");
	
	glColor3f(1,1,0);
	displayRasterText(-20,20,"ANAPHASE");
	
	glColor3f(1,1,0);
	displayRasterText(250,20,"TELOPHASE");
	glLineWidth(1);
}
void Interphase()
{
	glLoadIdentity();
	glTranslatef(0,0,0);	
	glColor3f(0.560784,0.560784, 0.737255);
	GLUquadric *cell= gluNewQuadric();
	gluDisk(cell,0.0,600.0,20,1);
	
	glLoadIdentity();
	glTranslatef(0,430,0);
	glColor3f(1,1,1);
	GLUquadric *cell_2= gluNewQuadric();
	gluDisk(cell_2,0.0,105.0,20,1);
	
	glLoadIdentity();
	glTranslatef(-20,430,0);
	glRotatef(150,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_2_inside1= gluNewQuadric();
	gluCylinder(cell_2_inside1, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(-30,400,0);
	glRotatef(270,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_2_inside2= gluNewQuadric();
	gluCylinder(cell_2_inside2, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(-5,420,0);
	glRotatef(60,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_2_inside3= gluNewQuadric();
	gluCylinder(cell_2_inside3, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(0,-100,0);	
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell1= gluNewQuadric();
	gluDisk(cell1,0.0,300.0,20,1);
	
	glLoadIdentity();
	glTranslatef(-100,70,0);	
	glColor3f(1,1,1);
	GLUquadric *cell2= gluNewQuadric();
	gluDisk(cell2,0.0,50.0,20,1);
	
	glColor3f(1,1,0);
	glBegin(GL_LINES);
		glVertex2f(50,-150);
		glVertex2f(80,-400);
	glEnd();
	
	glColor3f(1,1,0);
	glBegin(GL_LINES);
		glVertex2f(80,-150);
		glVertex2f(50,-400);
	glEnd();
	
	glColor3f(0,1,1);
	glBegin(GL_LINES);
		glVertex2f(-50,-60);
		glVertex2f(-20,-300);
	glEnd();
	
	glColor3f(0,1,1);
	glBegin(GL_LINES);
		glVertex2f(-20,-60);
		glVertex2f(-50,-300);
	glEnd();
	
	glColor3f(0,1,1);
	glBegin(GL_LINES);
		glVertex2f(150,-100);
		glVertex2f(180,-350);
	glEnd();
	
	glColor3f(0,1,1);
	glBegin(GL_LINES);
		glVertex2f(180,-100);
		glVertex2f(150,-350);
	glEnd();
	
	glColor3f(1,1,0);
	glBegin(GL_LINES);
		glVertex2f(250,0);
		glVertex2f(280,-200);
	glEnd();
	
	glColor3f(1,1,0);
	glBegin(GL_LINES);
		glVertex2f(280,0);
		glVertex2f(250,-200);
	glEnd();
	
	//pointing line
	glColor3f(1,1,0);
	glBegin(GL_LINES);
		glVertex2f(40,-410);
		glVertex2f(-250,-650);
	glEnd();
	
	glColor3f(1,1,0);
	glBegin(GL_LINES);
		glVertex2f(490,-620);
		glVertex2f(400,-560);
	glEnd();
	
	glColor3f(1,1,0);
	glBegin(GL_LINES);
		glVertex2f(-150,-250);
		glVertex2f(-500,-400);
	glEnd();
	
	glColor3f(1,1,0);
	displayRasterText1(-600,530,"INTERPHASE");
	
	glColor3f(1,1,1);
	displayRasterText(-300,-690,"Sister Chromatids");
	
	glColor3f(1,1,1);
	displayRasterText(-530,-430,"Nucleus");
	
	glColor3f(1,1,1);
	displayRasterText(500,-640,"Cell");
	
	glColor3f(1,1,1);
	displayRasterText(500,-750,"PRESS 'T' or 't' KEY");				
}
void last()
{
	glLoadIdentity();
	glTranslatef(-150,400,0);	
	glColor3f(0.560784,0.560784, 0.737255);
	GLUquadric *cell2= gluNewQuadric();
	gluDisk(cell2,0.0,180.0,20,1);
	
	glLoadIdentity();
	glTranslatef(-150,400,0);	
	glColor3f(1,1, 1);
	GLUquadric *cell3= gluNewQuadric();
	gluDisk(cell3,0.0,80.0,20,1);
	
	glLoadIdentity();
	glTranslatef(150,400,0);	
	glColor3f(0.560784,0.560784, 0.737255);
	GLUquadric *cell8= gluNewQuadric();
	gluDisk(cell8,0.0,180.0,20,1);
	
	glLoadIdentity();
	glTranslatef(150,400,0);	
	glColor3f(1,1, 1);
	GLUquadric *cell9= gluNewQuadric();
	gluDisk(cell9,0.0,80.0,20,1);
	
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(-280,-200);
		glVertex2f(-400,-550);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(0,-200);
		glVertex2f(120,-550);
	glEnd();
	
	glLoadIdentity();
	glTranslatef(-250,-350,0);	
	glColor3f(0.560784,0.560784, 0.737255);
	GLUquadric *cell4= gluNewQuadric();
	gluDisk(cell4,0.0,180.0,20,1);
	
	glLoadIdentity();
	glTranslatef(-250,-350,0);	
	glColor3f(1,1, 1);
	GLUquadric *cell5= gluNewQuadric();
	gluDisk(cell3,0.0,80.0,20,1);
	
	glLoadIdentity();
	glTranslatef(250,-350,0);	
	glColor3f(0.560784,0.560784, 0.737255);
	GLUquadric *cell6= gluNewQuadric();
	gluDisk(cell6,0.0,180.0,20,1);
	
	glLoadIdentity();
	glTranslatef(250,-350,0);	
	glColor3f(1,1, 1);
	GLUquadric *cell7= gluNewQuadric();
	gluDisk(cell7,0.0,80.0,20,1);
	
	glColor3f(1.0, 1.0, 0);
    displayRasterText1(-400,1000, "END PHASES");
    
	glColor3f(0,1,1);
	displayRasterText(-570,-220,"Cell-1");
	
	glColor3f(0,1,1);
	displayRasterText(-50,-220,"Cell-2");
	
	glColor3f(0,1,1);
	glBegin(GL_LINES);
		glVertex2f(150,700);
		glVertex2f(0,700);
	glEnd();
	
	glColor3f(0,1,1);
	displayRasterText(200,690,"Telophase");
	
	glColor3f(0,1,1);
	glBegin(GL_LINES);
		glVertex2f(200,-100);
		glVertex2f(100,-100);
	glEnd();
	
	glColor3f(0,1,1);
	displayRasterText(220,-110,"Cytokinesis");
	
	glLoadIdentity();
	glTranslatef(-170,430,0);
	glRotatef(150,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_3_inside1= gluNewQuadric();
	gluCylinder(cell_3_inside1, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(-180,400,0);
	glRotatef(270,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_3_inside2= gluNewQuadric();
	gluCylinder(cell_3_inside2, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(-155,420,0);
	glRotatef(60,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_3_inside3= gluNewQuadric();
	gluCylinder(cell_3_inside3, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(-250,-370,0);
	glRotatef(150,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_5_inside1= gluNewQuadric();
	gluCylinder(cell_5_inside1, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(-260,-370,0);
	glRotatef(270,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_5_inside2= gluNewQuadric();
	gluCylinder(cell_5_inside2, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(-280,-390,0);
	glRotatef(60,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_5_inside3= gluNewQuadric();
	gluCylinder(cell_5_inside3, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(270,-370,0);
	glRotatef(150,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_7_inside1= gluNewQuadric();
	gluCylinder(cell_7_inside1, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(260,-360,0);
	glRotatef(270,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_7_inside2= gluNewQuadric();
	gluCylinder(cell_7_inside2, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(225,-370,0);
	glRotatef(60,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_7_inside3= gluNewQuadric();
	gluCylinder(cell_7_inside3, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(150,420,0);
	glRotatef(150,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_9_inside1= gluNewQuadric();
	gluCylinder(cell_9_inside1, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(140,400,0);
	glRotatef(270,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_9_inside2= gluNewQuadric();
	gluCylinder(cell_9_inside2, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(155,400,0);
	glRotatef(60,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_9_inside3= gluNewQuadric();
	gluCylinder(cell_9_inside3, 5,10,55,10,1);
	
	glColor3f(1,1,1);
	displayRasterText1(-850,-800,"THANKYOU");
}
void drawPhases()
{	
	glLoadIdentity();
	glTranslatef(0,0,0);	
	glColor3f(0.560784,0.560784, 0.737255);
	GLUquadric *cell= gluNewQuadric();
	gluDisk(cell,0.0,600.0,20,1);
	
	
	
	glLoadIdentity();
	glTranslatef(0,0,0);	
	glColor3f(0.7,0.7, 0.737255);
	glPushMatrix();
	glRotatef(spin,0,0,90);
	GLUquadric *cells= gluNewQuadric();
	gluDisk(cells,0.0,550.0,20,1);
	glPopMatrix();
	
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(-80,430);
		glVertex2f(-450,5);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(-450,5);
		glVertex2f(-80,-430);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(-80,430);
		glVertex2f(-150,5);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(-80,-430);
		glVertex2f(-150,5);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(80,430);
		glVertex2f(450,5);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(450,5);
		glVertex2f(80,-430);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(80,430);
		glVertex2f(150,5);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(80,-430);
		glVertex2f(150,5);
	glEnd();
	
	glLoadIdentity();
	glTranslatef(0,-430,0);
	glColor3f(1,1,1);
	GLUquadric *cell_1= gluNewQuadric();
	gluDisk(cell_1,0.0,105.0,20,1);
	
	glLoadIdentity();
	glTranslatef(0,430,0);
	glColor3f(1,1,1);
	GLUquadric *cell_2= gluNewQuadric();
	gluDisk(cell_2,0.0,105.0,20,1);
	
	//shri this is inside drawing of that cell2
	glLoadIdentity();
	glTranslatef(-20,430,0);
	glRotatef(150,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_2_inside1= gluNewQuadric();
	gluCylinder(cell_2_inside1, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(-30,400,0);
	glRotatef(270,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_2_inside2= gluNewQuadric();
	gluCylinder(cell_2_inside2, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(-5,420,0);
	glRotatef(60,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_2_inside3= gluNewQuadric();
	gluCylinder(cell_2_inside3, 5,10,55,10,1);
	
	//shri now u r doing inside drawing of that cell1
	glLoadIdentity();
	glTranslatef(-20,-430,0);
	glRotatef(150,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_1_inside1= gluNewQuadric();
	gluCylinder(cell_1_inside1, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(-30,-430,0);
	glRotatef(270,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_1_inside2= gluNewQuadric();
	gluCylinder(cell_1_inside2, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(-5,-450,0);
	glRotatef(60,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_1_inside3= gluNewQuadric();
	gluCylinder(cell_1_inside3, 5,10,55,10,1);
	
	/*Horage decoration*/
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(1200,70);
		glVertex2f(1200,430);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex2f(1000,70);
		glVertex2f(1100,430);
	glEnd();
	
	glLoadIdentity();
	glTranslatef(650,430,0);
	glColor3f(1,1,1);
	GLUquadric *cell_3= gluNewQuadric();
	gluDisk(cell_3,0.0,80.0,20,1);
	
	glLoadIdentity();
	glTranslatef(650,430,0);
	glRotatef(270,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_3_inside1= gluNewQuadric();
	gluCylinder(cell_3_inside1, 5,10,55,10,1);
	
	glLoadIdentity();
	glTranslatef(600,400,0);
	glRotatef(60,1.0,1.0,1.0);
	glColor3f(0.184314, 0.184314, 0.309804);
	GLUquadric *cell_3_inside3= gluNewQuadric();
	gluCylinder(cell_3_inside3, 5,10,55,10,1);
	
	/*horage inneradu cell*/
	
	glLoadIdentity();
	glTranslatef(-570,560,0);
	glColor3f(0.137255,0.556863,0.419608);
	GLUquadric *cell_4= gluNewQuadric();
	gluDisk(cell_4,0.0,200.0,20,1);
	
	glLoadIdentity();
	glTranslatef(-570,660,0);
	glColor3f(1,1,1);
	GLUquadric *cell_6= gluNewQuadric();
	gluDisk(cell_6,0.0,50.0,20,1);
	
	glLoadIdentity();
	glTranslatef(-570,-600,0);
	glColor3f(0.137255,0.556863,0.419608);
	GLUquadric *cell_5= gluNewQuadric();
	gluDisk(cell_5,0.0,100.0,20,1);
	
	glLoadIdentity();
	glTranslatef(-570,-560,0);
	glColor3f(1,1,1);
	GLUquadric *cell_7= gluNewQuadric();
	gluDisk(cell_7,0.0,20.0,20,1);	
	
}
void chromosome_chroma()
{
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(55,40);
    glVertex2i(60,40 );
    glVertex2i(5,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(5,0);
    glVertex2i(-50, -75);
    glVertex2i(-50, -78);
    glVertex2i(-2, 10);
    glEnd();
    glPopMatrix();
}

void chromosome_chroma2()
{
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();
}
void chromosome_chroma3()
{
	glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(55,40);
    glVertex2i(60,40 );
    glVertex2i(5,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(5,0);
    glVertex2i(-50, -75);
    glVertex2i(-50, -78);
    glVertex2i(-2, 10);
    glEnd();
    glPopMatrix();
}
void chromosome_nuc()
{
    glColor3f(1,1,0);
    glPushMatrix();
    glTranslatef(380,451,0);
    chromosome_chroma2();
    glPopMatrix();
    
    glColor3f(0.184314, 0.184314, 0.309804);
    glPushMatrix();
    glTranslatef(380,450,0);
    GLUquadric *cell_c10= gluNewQuadric();
    gluDisk(cell_c10,0.0,15.0,20,1);
    glPopMatrix();
}
void chromosome_nuc1()
{
    glColor3f(1,1,0);
    glPushMatrix();
    glTranslatef(380,451,0);
    chromosome_chroma3();
    glPopMatrix();
    
    glColor3f(0.184314, 0.184314, 0.309804);
    glPushMatrix();
    glTranslatef(380,450,0);
    GLUquadric *cell_c10= gluNewQuadric();
    gluDisk(cell_c10,0.0,15.0,20,1);
    glPopMatrix();
}

void chromosome()
{
    glColor3f(1,1,0);
    glPushMatrix();
    glTranslatef(380,451,0);
    chromosome_chroma();
    glPopMatrix();
    
   	glColor3f(0.184314, 0.184314, 0.309804);
    glPushMatrix();
    glTranslatef(380,450,0);
   	GLUquadric *cell_c1= gluNewQuadric();
    gluDisk(cell_c1,0.0,15.0,20,1);
    glPopMatrix();
    
}

//anaphase nuclei
void chroma_nuclie1()
{
	glPushMatrix();
    glTranslatef(tx4,ty4,0);
    chromosome_nuc();
    glPopMatrix();
}

void chroma_nuclie2()
{
	glPushMatrix();
    glTranslatef(tx5,ty5,0);
    chromosome_nuc1();
    glPopMatrix();
}

void chroma_nuclie3()
{
	glPushMatrix();
    glTranslatef(tx6,ty6,0);
    chromosome_nuc();
    glPopMatrix();
}

void chroma_nuclie4()
{
	glPushMatrix();
    glTranslatef(tx7,ty7,0);
    chromosome_nuc1();
    glPopMatrix();
}

void chroma_nuclie5()
{
	glPushMatrix();
    glTranslatef(tx8,ty8,0);
    chromosome_nuc();
    glPopMatrix();
}

void chroma_nuclie6()
{
	glPushMatrix();
    glTranslatef(tx9,ty9,0);
    chromosome_nuc1();
    glPopMatrix();
}

void chroma_nuclie7()
{
	glPushMatrix();
    glTranslatef(tx10,ty10,0);
    chromosome_nuc();
    glPopMatrix();
}

void chroma_nuclie8()
{
	glPushMatrix();
    glTranslatef(tx11,ty11,0);
    chromosome_nuc1();
    glPopMatrix();
}


//all chromosomes
void chromosome1()
{
    glPushMatrix();
    glTranslatef(0,-50,0);
    chromosome();
    glPopMatrix();

}
void chromosome2()
{
	glPushMatrix();
    glTranslatef(-300,80,0);
    chromosome();
    glPopMatrix();
}
void chromosome3()
{
	glPushMatrix();
    glTranslatef(-150,80,0);
    chromosome();
    glPopMatrix();
}

void chromosome4()
{
	glPushMatrix();
    glTranslatef(-100,-10,0);
    chromosome();
    glPopMatrix();
}

void chromosome5()
{
	glPushMatrix();
    glTranslatef(tx,ty,0);
    chromosome();
    glPopMatrix();
}

void chromosome6()
{
	glPushMatrix();
    glTranslatef(tx1,ty1,0);
    chromosome();
    glPopMatrix();
}

void chromosome7()
{
	glPushMatrix();
    glTranslatef(tx2,ty2,0);
    chromosome();
    glPopMatrix();
}

void chromosome8()
{
	glPushMatrix();
    glTranslatef(tx3,ty3,0);
    chromosome();
    glPopMatrix();
}
//here it ends shriiii:)))

void spinc()
{
	spin=spin+0.02;
	glutPostRedisplay();
}

void translation()
{
	spin=spin+0.02;
	
	tx=tx-0.08;
	ty=ty+0.04;
	if(tx<-250 && ty>110)
	{
		tx=-250;
		ty=110;
	}
	
	tx1=tx1+0.05;
	ty1=ty1+0.05;
	if(tx1>50 && ty1>60)
	{
		tx1=50;
		ty1=110;
	}
	
	tx2=tx2+0.06;
	ty2=ty2+0.04;
	if(tx2>340 && ty2>110)
	{
		tx2=340;
		ty2=110;
	}
	
	tx3=tx3+0.08;
	ty3=ty3+0.04;
	if(tx3>640 && ty3>110)
	{
		tx3=640;
		ty3=110;
	}
	glutPostRedisplay();
}
void Atranslation()
{
	spin=spin+0.02;
	
	tx4=tx4+0.05;
	ty4=ty4+0.05;
	if(tx4>-98 && ty4>300)
	{
		tx4=-98;
		ty4=300;
	}
	
	tx5=tx5+0.05;
	ty5=ty5-0.05;
	if(tx5>-98 && ty5<-80)
	{
		tx5=-98;
		ty5=-80;
	}
	
	tx6=tx6+0.01;
	ty6=ty6+0.06;
	if(tx6>82 && ty6>300)
	{
		tx6=82;
		ty6=300;
	}
	
	tx7=tx7+0.01;
	ty7=ty7-0.06;
	if(tx7>82 && ty7<-80)
	{
		tx7=82;
		ty7=-80;
	}
	
	tx8=tx8-0.012;
	ty8=ty8+0.06;
	if(tx8<320 && ty8>300)
	{
		tx8=310;
		ty8=300;
	}
	
	tx9=tx9-0.01;
	ty9=ty9-0.06;
	if(tx9<320 && ty9<-80)
	{
		tx9=310;
		ty9=-80;
	}
	
	tx10=tx10-0.043;
	ty10=ty10+0.05;
	if(tx10<474 && ty10>300)
	{
		tx10=474;
		ty10=300;
	}
	
    tx11=tx11-0.045;
	ty11=ty11-0.05;
	if(tx11<470 && ty11<-80)
	{
		tx11=470;
		ty11=-80;
	}	
	glutPostRedisplay();		
}
//phases illinda shri
void drawProphase()
{	
	glColor3f(0.184314, 0.184314, 0.309804);
	glBegin(GL_LINES);
		glVertex2f(150,350);
		glVertex2f(50,400);
	glEnd();

	glColor3f(0.184314, 0.184314, 0.309804);
	glBegin(GL_LINES);
		glVertex2f(160,350);
		glVertex2f(400,300);
	glEnd();
	
	glColor3f(0.184314, 0.184314, 0.309804);
	glBegin(GL_LINES);
		glVertex2f(410,300);
		glVertex2f(560,400);
	glEnd();
	
	glColor3f(0.184314, 0.184314, 0.309804);
	glBegin(GL_LINES);
		glVertex2f(570,400);
		glVertex2f(550,500);
	glEnd();
	
	glColor3f(0.184314, 0.184314, 0.309804);
	glBegin(GL_LINES);
		glVertex2f(560,500);
		glVertex2f(250,700);
	glEnd();
	
	glColor3f(0.184314, 0.184314, 0.309804);
	glBegin(GL_LINES);
		glVertex2f(260,700);
		glVertex2f(10,650);
	glEnd();
	
	glColor3f(0.184314, 0.184314, 0.309804);
	glBegin(GL_LINES);
		glVertex2f(0,650);
		glVertex2f(25,500);
	glEnd();
	
	glColor3f(0.184314, 0.184314, 0.309804);
	glBegin(GL_LINES);
		glVertex2f(25,500);
		glVertex2f(50,400);
	glEnd();
	
    glPushMatrix();
    chromosome1();
    glPopMatrix();
    
    glPushMatrix();
    chromosome2();
    glPopMatrix();
    
    glPushMatrix();
    chromosome3();
    glPopMatrix();

	glPushMatrix();
    chromosome4();
    glPopMatrix();
    
    
	glColor3f(0,1,1);
	glBegin(GL_LINES);
		glVertex2f(370,370);
		glVertex2f(300,-50);
	glEnd();
	glColor3f(1,1,1);
	displayRasterText(280,-90,"Chromosome");
		
	glColor3f(0,1,1);
	glBegin(GL_LINES);
		glVertex2f(760,250);
		glVertex2f(970,140);
	glEnd();
	glColor3f(1,1,1);
	displayRasterText(980,120,"Spindle Apparatus");
		
	glColor3f(0,1,1);
	glBegin(GL_LINES);
		glVertex2f(70,250);
		glVertex2f(-60,160);
	glEnd();
	glColor3f(1,1,1);
	displayRasterText(-90,140,"Cell");
		
	glColor3f(1,0,1);
	displayRasterText1(880,-60,"PROPHASE!!!");
	
	glColor3f(1,1,1);
	displayRasterText(900,-130,"PRESS 'M' or 'm' KEY");
}

void drawMetaphase()
{
	glPushMatrix();
    chromosome5();
    glPopMatrix();
    
    glPushMatrix();
    chromosome6();
    glPopMatrix();
    
    glPushMatrix();
    chromosome7();
    glPopMatrix();
	
	glPushMatrix();
    chromosome8();
    glPopMatrix();
    
    glColor3f(0,1,1);
	glBegin(GL_LINES);
		glVertex2f(760,250);
		glVertex2f(970,140);
	glEnd();
	glColor3f(1,1,1);
	displayRasterText(980,120,"Spindle Apparatus");
		
	glColor3f(0,1,1);
	glBegin(GL_LINES);
		glVertex2f(70,250);
		glVertex2f(-60,160);
	glEnd();
	glColor3f(1,1,1);
	displayRasterText(-90,140,"Cell");
		
	glColor3f(1,0,1);
	displayRasterText1(880,-60,"METAPHASE!!!");
	
	glColor3f(1,1,1);
	displayRasterText(900,-130,"PRESS 'A' or 'a' KEY");	
}

void drawAnaphase()
{
	glPushMatrix();
    chroma_nuclie1();
    glPopMatrix();
    
    glPushMatrix();
    chroma_nuclie2();
    glPopMatrix();
    
    glPushMatrix();
    chroma_nuclie3();
    glPopMatrix();
    
    glPushMatrix();
    chroma_nuclie4();
    glPopMatrix();
    
    glPushMatrix();
    chroma_nuclie5();
    glPopMatrix();
    
    glPushMatrix();
    chroma_nuclie6();
    glPopMatrix();
    
    glPushMatrix();
    chroma_nuclie7();
    glPopMatrix();
    
    glPushMatrix();
    chroma_nuclie8();
    glPopMatrix();
    
    glColor3f(0,1,1);
	glBegin(GL_LINES);
		glVertex2f(760,250);
		glVertex2f(970,140);
	glEnd();
	glColor3f(1,1,1);
	displayRasterText(980,120,"Spindle Apparatus");
		
	glColor3f(0,1,1);
	glBegin(GL_LINES);
		glVertex2f(70,250);
		glVertex2f(-60,160);
	glEnd();
	glColor3f(1,1,1);
	displayRasterText(-90,140,"Cell");
		
	glColor3f(1,0,1);
	displayRasterText1(880,-60,"ANAPHASE!!!");
	
	glColor3f(1,1,1);
	displayRasterText(900,-130,"PRESS 'Y' or 'y' KEY");
}

void keyOperations() 
{
        if (keyStates[13] == true && viewPage == INTRO) {
            viewPage = PHASES;
        }
        else if(keyStates[27] == true && viewPage == INTRO )
        {
        	exit(0);
		}
        else if(keyStates['Q']==true ||keyStates['q']==true && viewPage == PHASES)
		{
			viewPage=MITOSIS;
		}
		else if(keyStates['W']==true ||keyStates['w']==true && viewPage == MITOSIS)
		{
			viewPage=GROWTH;
		}
		else if(keyStates['E']==true ||keyStates['e']==true && viewPage == GROWTH)
		{
			viewPage=PMAT;
		}
		else if(keyStates['R']==true ||keyStates['r']==true && viewPage == PMAT)
		{
			viewPage=INTERPHASE;
		}
		else if(keyStates['T']==true ||keyStates['t']==true && viewPage == INTERPHASE)
		{
			viewPage=MENU;
		}
           
        if (keyStates['P']==true||keyStates['p']==true && viewPage == MENU)
    	{	
    		if(prophase==false){
    			anaphase=false;
				metaphase=false;
				prophase=true;
					
				drawProphase();		 	
				glutPostRedisplay();
			}
			
		}
   
   		if (keyStates['M']==true ||keyStates['m']==true && viewPage == MENU){
    		if(metaphase==false){
    			prophase=false;
    			anaphase=false;
				metaphase=true;	
				drawMetaphase();		 	
				glutPostRedisplay();
			}
		}
  		
		if (keyStates['A']==true ||keyStates['a']==true && viewPage == MENU) {
    		if(anaphase ==false){
    			metaphase=false;
    			prophase=false;
    			anaphase=true;
				drawAnaphase();		
				glutPostRedisplay();	
			}
    	}
    	
	
    	else if(keyStates['Y']==true ||keyStates['y']==true && anaphase==true)
		{
			viewPage=LAST;
		}				
}

void display()
{
    keyOperations();
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    switch (viewPage)
    {
        case INTRO:
                introScreen();
                break;
        case PHASES:
        		glutIdleFunc(arrowTranslation);
				Phases();
				glutPostRedisplay();
                break;
        case MITOSIS:
        		Mitosis();
        		glutPostRedisplay();
        		break;
        		
        case GROWTH:
        		Growth();
        		glutPostRedisplay();
        		break;
        case PMAT:
        		Mitosis_phases();
        		glutPostRedisplay();
        		break;
        case INTERPHASE:
        		Interphase();
        		glutPostRedisplay();
        		break;
        case MENU:
                drawPhases();
                if(viewPage==MENU && prophase==false && metaphase==false && anaphase==false){
                	glColor3f(1,1,1);
					displayRasterText(900,-130,"PRESS 'P' or 'p' KEY");
				}			
				if(prophase==true && viewPage == MENU )
				{
					glutIdleFunc(spinc);
					drawProphase();
					glutPostRedisplay();
				}
				else if(metaphase==true && viewPage==MENU)
				{
					glutIdleFunc(translation);
					drawMetaphase();
					glutPostRedisplay();
				}
				else if(anaphase==true && viewPage==MENU)
				{
					glutIdleFunc(Atranslation);
					drawAnaphase();
					glutPostRedisplay();
				}
				break;
		case LAST:
				last();
				glutPostRedisplay();
				break;
	}
	glFlush();
    glLoadIdentity();
    glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y)
{
        keyStates[key] = true;
        glutPostRedisplay();
}


void keyReleased(unsigned char key, int x, int y)
{
        keyStates[key] = false;
        glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
	glutInitWindowSize(800,648);
	glutInitWindowPosition(250,0);
	glutCreateWindow("4SF19CS156");
	glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyReleased);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
