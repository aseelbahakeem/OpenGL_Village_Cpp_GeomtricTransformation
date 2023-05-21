#include <Windows.h>
//#include <GL/GL.H>
#include <GL/glut.h>
#include <iostream>
using namespace std;

float shift = 0; 

//note that when applying the vertices in a sqaure apply it like this:
//first vertex is going to be at first quarter 
//second one is going to be at seconed quarter
//third one is going to be at third quarter
//fourth one is going to be at fourth quarter

void drawCircle(float cx, float cy, float r, int num_segments, float size) {
	float theta = 3.1415926 * 2 / float(num_segments);

	float tangetial_factor =  tanf(theta); //caclutate the tangetial factor

	float radial_factor =  cosf(theta); //calculate the radial factor

	float x = r; //start at angle 0

	float y = 0; 
	glLineWidth(2.0);
	//glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++) {
		glVertex2f(size*(x + cx), size*(y + cy)); //output vertex
		
		//caclutate the tangetial vector
		//note that: the radial vector is (x,y)
		// to get tangetial vector we flip those coordinate and negate one of them

		float tx = -y;
		float ty = x; 

		//add the tangetial vector

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		//correct uaing the radial factor
		x *= radial_factor;
		y *= radial_factor; 
	}

}

float boatposition = 0.0f;
void boat() {
	//boat 
	//wood of the boat

	glPushMatrix();
	glTranslatef(boatposition, 0.0f, -1.0f);
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
	glColor3ub(145, 89, 58);
	glVertex2f(-0.01+shift, 0.34);/*0.14*/ glVertex2f(-0.01+shift, 0.6);/*0.4*/
	glVertex2f(-0.1+shift, 0.34);/*0.14*/	glVertex2f(-0.01+shift, 0.58);/*0.38*/
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(252, 25, 0);
	glVertex2f(-0.01 + shift, 0.58);/*0.38*/
	glVertex2f(-0.01 + shift, 0.3);/*0.1*/
	glVertex2f(0.14 + shift, 0.3);/*0.1*/

	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(252, 185, 0);
	glVertex2f(-0.12 + shift, 0.27);/*0.07*/
	glVertex2f(-0.1 + shift, 0.24);/*0.04*/
	glVertex2f(0.1 + shift, 0.24);/*0.04*/
	glVertex2f(0.12 + shift, 0.27);/*0.07*/


	glEnd();
	glPopMatrix();

}
float SunRotationAngle = 0.0f;
float scale = 1.0; 
void Sun() {
	 
	glPushMatrix();
	glRotatef(SunRotationAngle, 0.0f, 0.0f, 1.0f); 
	//line 1 for the sun light
	glColor3f(0.98823529, 0.69803922, 0.17647059);
	glBegin(GL_LINES);
	glVertex2f(0.3, 0.75);
	glVertex2f(0.32, 0.82);
	glEnd();

	//line 2 for the sun light
	glColor3f(0.98823529, 0.69803922, 0.17647059);
	glBegin(GL_LINES);
	glVertex2f(0.28, 0.68);
	glVertex2f(0.26, 0.62);
	glEnd();

	//line 3 for the sun light
	glColor3f(0.98823529, 0.69803922, 0.17647059);
	glBegin(GL_LINES);
	glVertex2f(0.33, 0.7);
	glVertex2f(0.4, 0.67);
	glEnd();
	
	//line 4 for the sun light
	glColor3f(0.98823529, 0.69803922, 0.17647059);
	glBegin(GL_LINES);
	glVertex2f(0.2, 0.76);
	glVertex2f(0.25, 0.74);
	glEnd();
	
	//fill sun circle
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.98823529, 0.69803922, 0.17647059);
	drawCircle(0.5, 1.2, 0.099, 360, 0.6f);
	glEnd();

	glPopMatrix();
	
}


void house() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Green Grass above the river 
	glBegin(GL_POLYGON);

	glColor3f(0.32941176, 0.50980392, 0.20784314); glVertex2f(1.2, 0.4);
	glColor3f(0.32941176, 0.50980392, 0.20784314); glVertex2f(-1.0, 0.4);
	glColor3f(0.32941176, 0.50980392, 0.20784314); glVertex2f(-1.0, 0.3);
	glColor3f(0.32941176, 0.50980392, 0.20784314); glVertex2f(1.2, 0.3);
	
	glEnd();
	//River 
	glBegin(GL_POLYGON);

	glColor3f(0.17254902, 0.62352941, 0.8); glVertex2f(1.2, 0.3);
	glColor3f(0.17254902, 0.62352941, 0.8); glVertex2f(-1.0, 0.3);
	glColor3f(0.17254902, 0.62352941, 0.8); glVertex2f(-1.0, 0.18);
	glColor3f(0.17254902, 0.62352941, 0.8); glVertex2f(1.2, 0.18);

	glEnd();

	//boarders of the River
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.17254902, 0.62352941, 0.8); glVertex2f(1.2, 0.3);
	glColor3f(0.17254902, 0.62352941, 0.8); glVertex2f(-1.0, 0.3);
	glColor3f(0.17254902, 0.62352941, 0.8); glVertex2f(-1.0, 0.18);
	glColor3f(0.17254902, 0.62352941, 0.8); glVertex2f(1.2, 0.18);
	glEnd();

	//Green Grass below the river 
	glBegin(GL_POLYGON);

	glColor3f(0.32941176, 0.50980392, 0.20784314); glVertex2f(1.2, 0.18);
	glColor3f(0.32941176, 0.50980392, 0.20784314); glVertex2f(-1.0, 0.18);
	glColor3f(0.32941176, 0.50980392, 0.20784314); glVertex2f(-1.0,-0.7);
	glColor3f(0.32941176, 0.50980392, 0.20784314); glVertex2f(1.2, -0.7);

	glEnd();

	//Mountain 1
	glBegin(GL_TRIANGLES);
	glColor3f(0.21960784, 0.34117647, 0.1372549); glVertex2f(1.5, 0.35);
	glColor3f(0.21960784, 0.34117647, 0.1372549); glVertex2f(0.98, 0.78);
	glColor3f(0.21960784, 0.34117647, 0.1372549); glVertex2f(0.4, 0.35);
	glEnd();

	//Boarder of the Mountain 1
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.22, 0.58);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.59, 0.19);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.15, 0.19);
	glEnd();

	//Mountain 2
	glBegin(GL_TRIANGLES);
	glColor3f(0.21960784, 0.34117647, 0.1372549); glVertex2f(0.74, 0.38);
	glColor3f(0.21960784, 0.34117647, 0.1372549); glVertex2f(-0.5, 0.89);
	glColor3f(0.21960784, 0.34117647, 0.1372549); glVertex2f(-1.7, 0.38);
	glEnd();

	//Boarder of the Mountain 2
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.22, 0.58);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.59, 0.19);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.15, 0.19);
	glEnd();

	//front yard 1
	glBegin(GL_POLYGON);

	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(0.72, -0.3);
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(0.27, -0.3);

	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(0.2, -0.7);
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(0.81, -0.71);

	glEnd();

	//front yard 2

	glBegin(GL_POLYGON);

	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(0.26, -0.4);
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(-0.01, -0.4);
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(-0.01, -0.54);
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(0.23, -0.54);
	

	glEnd();

	//front yard 3

	glBegin(GL_POLYGON);

 
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(-0.04, -0.3);
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(-0.18, -0.3);
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(-0.25, -0.54);
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(0.03, -0.54);
 


	glEnd();

	//Boarder of the front yard
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(0.72, -0.3);
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(0.27, -0.3);
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(0.26, -0.4);
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(-0.01, -0.4);
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(-0.04, -0.3);
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(-0.18, -0.3);
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(-0.25, -0.54);
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(0.23, -0.54);
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(0.2, -0.7);
	glColor3f(0.89019608, 0.85490196, 0.78431373); glVertex2f(0.81, -0.71);
	glEnd();

	//walk way 
	glBegin(GL_POLYGON);

	glColor3f(0.74117647, 0.71764706, 0.68627451); glVertex2f(1.2, -0.7);
	glColor3f(0.74117647, 0.71764706, 0.68627451); glVertex2f(-1.0, -0.7);
	glColor3f(0.74117647, 0.71764706, 0.68627451); glVertex2f(-1.0, -0.8);
	glColor3f(0.74117647, 0.71764706, 0.68627451); glVertex2f(1.2,-0.8);

	glEnd();

	//boarders of the walk way
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.74117647, 0.71764706, 0.68627451); glVertex2f(1.2, -0.7);
	glColor3f(0.74117647, 0.71764706, 0.68627451); glVertex2f(-1.0, -0.7);
	glColor3f(0.74117647, 0.71764706, 0.68627451); glVertex2f(-1.0, -0.8);
	glColor3f(0.74117647, 0.71764706, 0.68627451); glVertex2f(1.2, -0.8);
	glEnd();

	//Street
	glBegin(GL_POLYGON);

	glColor3f(0.53333333, 0.54117647058, 0.49803921568); glVertex2f(1.2, -0.8);
	glColor3f(0.53333333, 0.54117647058, 0.49803921568); glVertex2f(-1.1, -0.8);
	glColor3f(0.53333333, 0.54117647058, 0.49803921568); glVertex2f(-1.1, -1.0);
	glColor3f(0.53333333, 0.54117647058, 0.49803921568); glVertex2f(1.2, -1.0);

	glEnd();

	//Street Boarders
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.53333333, 0.54117647058, 0.49803921568); glVertex2f(1.2, -0.8);
	glColor3f(0.53333333, 0.54117647058, 0.49803921568); glVertex2f(-1.1, -0.8);
	glColor3f(0.53333333, 0.54117647058, 0.49803921568); glVertex2f(-1.1, -1.0);
	glColor3f(0.53333333, 0.54117647058, 0.49803921568); glVertex2f(1.2, -1.0);
	glEnd();

	boat();

	//garagge 
	glBegin(GL_POLYGON);

	glColor3f(0.969, 0.906, 0.749); glVertex2f(0.85, 0.14);
	glColor3f(0.969, 0.906, 0.749); glVertex2f(0.15, 0.14);
	glColor3f(0.969, 0.906, 0.749); glVertex2f(0.15, -0.3);
	glColor3f(0.969, 0.906, 0.749); glVertex2f(0.85f, -0.3);

	glEnd();

	//boarders of the garagge
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.85, 0.14);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.15, 0.14);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.15, -0.3);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.85f, -0.3);
	glEnd();

	//the garagge roof
	glBegin(GL_POLYGON);
	glColor3f(0.99607843, 0.34117647, 0.13333333); glVertex2f(0.83, 0.41);
	glColor3f(0.99607843, 0.34117647, 0.13333333); glVertex2f(0.09, 0.41);
	glColor3f(0.99607843, 0.34117647, 0.13333333); glVertex2f(0.09, 0.14);
	glColor3f(0.99607843, 0.34117647, 0.13333333); glVertex2f(0.89, 0.14);
	glEnd();

	//boarders of garagge roof
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.83, 0.41);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.09, 0.41);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.09, 0.14);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.89, 0.14);


	glEnd();
	
	//garagge door
	glBegin(GL_POLYGON);

	glColor3f(0.90588235, 0.57647059, 0.26666667); glVertex2f(0.69, 0.02);
	glColor3f(0.90588235, 0.57647059, 0.26666667); glVertex2f(0.3, 0.02);
	glColor3f(0.90588235, 0.57647059, 0.26666667); glVertex2f(0.3, -0.3);
	glColor3f(0.90588235, 0.57647059, 0.26666667); glVertex2f(0.69, -0.3);

	glEnd();

	//boarders of the garagge door
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.69, 0.02);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.3, 0.02);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.3, -0.3);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.69, -0.3);
	glEnd();

	//above the garagge door
	glBegin(GL_POLYGON);
	 
	glColor3f(0.98431373, 0.97254902, 0.98823529); glVertex2f(0.71, 0.08);
	glColor3f(0.98431373, 0.97254902, 0.98823529); glVertex2f(0.28, 0.08);
	glColor3f(0.98431373, 0.97254902, 0.98823529); glVertex2f(0.28, 0.02);
	glColor3f(0.98431373, 0.97254902, 0.98823529); glVertex2f(0.71, 0.02);

	glEnd();

	//boarders of the above the garagge door
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.71, 0.08);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.28, 0.08);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.28, 0.02);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.71, 0.02);
	glEnd();
	
	//garagge left window 
	glBegin(GL_POLYGON);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(0.42, -0.01);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(0.34, -0.01);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(0.34, -0.08);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(0.42, -0.08);

	glEnd();

	//Boarder of the garagge left window
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.42, -0.01);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.34, -0.01);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.34, -0.08);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.42, -0.08);

	glEnd();
	//horizontal line for the left window
	glColor3f(0.36078, 0.00392157, 0);
	glBegin(GL_LINES);
	glVertex2f(0.34, -0.045);
	glVertex2f(0.42, -0.045);
	glEnd();

	//garagge middle window 
	glBegin(GL_POLYGON);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(0.53, -0.01);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(0.45, -0.01);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(0.45, -0.08);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(0.53, -0.08);

	glEnd();

	//Boarder of the garagge middle window
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.53, -0.01);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.45, -0.01);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.45, -0.08);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.53, -0.08);

	glEnd();
	//horizontal line for the middle window
	glColor3f(0.36078, 0.00392157, 0);
	glBegin(GL_LINES);
	glVertex2f(0.45, -0.045);
	glVertex2f(0.53, -0.045);
	glEnd();

	//garagge right window 
	glBegin(GL_POLYGON);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(0.56, -0.01);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(0.64, -0.01);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(0.64, -0.08);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(0.56, -0.08);

	glEnd();

	//Boarder of the garagge right window
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.56, -0.01);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.64, -0.01);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.64, -0.08);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.56, -0.08);

	glEnd();
	//horizontal line for the right window
	glColor3f(0.36078, 0.00392157, 0);
	glBegin(GL_LINES);
	glVertex2f(0.56, -0.045);
	glVertex2f(0.64, -0.045);
	glEnd();

	//the chimney
	glBegin(GL_POLYGON);
	glColor3f(0.969, 0.906, 0.749); glVertex2f(0.09, 0.45);
	glColor3f(0.969, 0.906, 0.749); glVertex2f(-0.03, 0.45);
	glColor3f(0.969, 0.906, 0.749); glVertex2f(-0.03, 0.34);
	glColor3f(0.969, 0.906, 0.749); glVertex2f(0.09, 0.26);

	glEnd();

	//boarders of the chimney 
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.09, 0.45);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.03, 0.45);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.03, 0.34);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.09, 0.26);
	glEnd();

	//above the chimney
	glBegin(GL_POLYGON);
	glColor3f(0.99607843, 0.34117647, 0.13333333); glVertex2f(-0.05, 0.45);
	glColor3f(0.99607843, 0.34117647, 0.13333333); glVertex2f(0.12, 0.45);
	glColor3f(0.99607843, 0.34117647, 0.13333333); glVertex2f(0.12, 0.5);
	glColor3f(0.99607843, 0.34117647, 0.13333333); glVertex2f(-0.05, 0.5);

	glEnd();

	//boarders for above of the chimney 
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.05, 0.45);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.12, 0.45);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.12, 0.5);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.05, 0.5);
	glEnd();

	//house roof
	glBegin(GL_TRIANGLES);
	glColor3f(0.99607843, 0.34117647, 0.13333333); glVertex2f(-0.22, 0.58);
	glColor3f(0.99607843, 0.34117647, 0.13333333); glVertex2f(-0.59, 0.19);
	glColor3f(0.99607843, 0.34117647, 0.13333333); glVertex2f(0.15, 0.19);
	glEnd();

	//Boarder of the roof
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.22, 0.58);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.59, 0.19);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.15, 0.19);
	glEnd();
	
	glPushMatrix();
	glScalef(scale, scale, 0.0f);

	//First circle 
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0);
	drawCircle(-0.29, 0.45, 0.12, 360, 0.77f);
	glEnd();

	//fill first circle
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.98431373, 0.97254902, 0.98823529);
	drawCircle(-0.29, 0.45, 0.12, 360, 0.77f);
	glEnd();

	//Second circle
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0);
	drawCircle(-0.37, 0.57, 0.099, 360, 0.6f);
	glEnd();

	//fill second circle
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.98823529, 0.69803922, 0.17647059);
	drawCircle(-0.37, 0.57, 0.099, 360, 0.6f);
	glEnd();

	//vertical line for the circles
	glColor3f(0.36078, 0.00392157, 0);
	glBegin(GL_LINES);
	glVertex2f(-0.226, 0.4);
	glVertex2f(-0.226,0.28 );
	glEnd();

	//horizontal line for the circles
	glColor3f(0.36078, 0.00392157, 0);
	glBegin(GL_LINES);
	glVertex2f(-0.28, 0.34);
	glVertex2f(-0.16, 0.34);

	glEnd();

	glPopMatrix();
	//body of the house 

	glBegin(GL_POLYGON);
	 
	glColor3f(0.969, 0.906, 0.749); glVertex2f(0.15f, 0.19f);
	glColor3f(0.969, 0.906, 0.749); glVertex2f(-0.59f, 0.19f);
	glColor3f(0.969, 0.906, 0.749); glVertex2f(-0.59f, -0.3f);
	glColor3f(0.969, 0.906, 0.749); glVertex2f(0.15f, -0.3f);

	glEnd();

	//Boarder of the house
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.15f, 0.19f);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.59f, 0.19f);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.59f, -0.3f);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.15f, -0.3f);
	glEnd();

	//right window 
	glBegin(GL_POLYGON);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(0.1, 0.11);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(0.01, 0.11);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(0.01, -0.25);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(0.1, -0.25);
	
	glEnd();

	//Boarder of the right window
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.1, 0.11);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.01, 0.11);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.01, -0.25);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(0.1, -0.25);
	glEnd();

	//vertical line for the right window
	glColor3f(0.36078, 0.00392157, 0);
	glBegin(GL_LINES);
	glVertex2f(0.053, 0.11);
	glVertex2f(0.053, -0.25);
	glEnd();

	//horizontal line for the right window
	glColor3f(0.36078, 0.00392157, 0);
	glBegin(GL_LINES);
	glVertex2f(0.01, -0.08); //y axis moves the object, the x axis resize the object
	glVertex2f(0.1, -0.08);
	glEnd();

	//left-left window 
	glBegin(GL_POLYGON);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(-0.55, -0.25);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(-0.55, 0.1);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(-0.4, 0.1);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(-0.4, -0.25);
	
	glEnd();

	//Boarder of the left-left window
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.4, 0.1);
	glColor3f(0.36078, 0.00392157, 0);  glVertex2f(-0.55, 0.1);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.55, -0.25);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.4, -0.25);
	
	glEnd();
	//vertical line for the left window
	glColor3f(0.36078, 0.00392157, 0);
	glBegin(GL_LINES);
	glVertex2f(-0.55, -0.08);
	glVertex2f(-0.4, -0.08);
	glEnd();

	//horizontal line for the window
	glColor3f(0.36078, 0.00392157, 0);
	glBegin(GL_LINES);
	glVertex2f(-0.475, 0.1); //y axis moves the object, the x axis resize the object
	glVertex2f(-0.475, -0.25);
	glEnd();

	// left - right window
		glBegin(GL_POLYGON);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(-0.25, 0.1);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(-0.4, 0.1);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(-0.4, -0.25);
	glColor3f(0.5843, 0.87843, 1); glVertex2f(-0.25, -0.25);

	glEnd();

	//Boarder of the left-right window
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.25, 0.1);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.4, 0.1);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.4, -0.25);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.25, -0.25);

	glEnd();
	//vertical line for the left-right window
	glColor3f(0.36078, 0.00392157, 0);
	glBegin(GL_LINES);
	glVertex2f(-0.4, -0.08);
	glVertex2f(-0.25, -0.08);
	glEnd();

	//horizontal line for the window
	glColor3f(0.36078, 0.00392157, 0);
	glBegin(GL_LINES);
	glVertex2f(-0.33, 0.1); //y axis moves the object, the x axis resize the object
	glVertex2f(-0.33, -0.25);
	glEnd();

	//Door
	glBegin(GL_POLYGON);
	glColor3f(0.90588235, 0.57647059, 0.26666667); glVertex2f(-0.04, 0.07);
	glColor3f(0.90588235, 0.57647059, 0.26666667); glVertex2f(-0.18, 0.07);
	glColor3f(0.90588235, 0.57647059, 0.26666667); glVertex2f(-0.18,-0.3);
	glColor3f(0.90588235, 0.57647059, 0.26666667); glVertex2f(-0.04, -0.3);

	glEnd();

	//boarders of the door 
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.04, 0.07);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.18, 0.07);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.18, -0.3);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.04, -0.3);
	glEnd();

	//above the door 
	glBegin(GL_POLYGON);
	glColor3f(0.98431373, 0.97254902, 0.98823529); glVertex2f(-0.01, 0.11);
	glColor3f(0.98431373, 0.97254902, 0.98823529); glVertex2f(-0.21, 0.11);
	glColor3f(0.98431373, 0.97254902, 0.98823529); glVertex2f(-0.21, 0.07);
	glColor3f(0.98431373, 0.97254902, 0.98823529); glVertex2f(-0.01, 0.07);

	glEnd();

	//boarders above the door
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.01, 0.11);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.21, 0.11);
	glColor3f(0.36078, 0.00392157, 0); glVertex2f(-0.21, 0.07);
	glColor3f(0.36078, 0.00392157, 0);  glVertex2f(-0.01, 0.07);

	glEnd();

	//door handles
	glBegin(GL_LINE_LOOP);
	glColor3f(0.36078, 0.00392157, 0);
	drawCircle(-1.5, -1.4, -0.1, 360, 0.1f);
	glEnd();

	Sun();
}


void display() {
	
	glClearColor(0.64313725, 0.8, 0.88627451,0);
	house();
	glutSwapBuffers(); //the reason way the screen does not keep redrawing everytime i enter the keyboard functionality
	glFlush();
}
void keyboard(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		//move boat left
		boatposition -= 0.1f;
		break;
	case GLUT_KEY_RIGHT:
		//move boat right
		boatposition += 0.1f;
		break;
	case GLUT_KEY_UP:
		SunRotationAngle += .1f;
		break;
	case GLUT_KEY_DOWN:
		SunRotationAngle -= .1f;
		break;
	}
	glutPostRedisplay();
}
	void keyboardScalling(unsigned char key, int x, int y) {
		switch (key) {
		case 'b': //b stands for bigger
			scale += 0.1f;
			break; 
		case 's': //s stands for smaller
			scale -= 0.1f;
			break;
		}
		glutPostRedisplay();
	}
 
int main(int argc, char** argv) {
	//initalize GLUT 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(900, 900);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("A Simple Village");
	//register the display callback function
	glutDisplayFunc(display);
	//register the keyboard callback function
	glutSpecialFunc(keyboard);
	glutKeyboardFunc(keyboardScalling);
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glutMainLoop();
 }