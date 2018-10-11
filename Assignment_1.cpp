
#include "pch.h"
#include <iostream>
#include <stdlib.h> //Needed for "exit" function

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

//Called when a key is pressed
void handleKeypress(unsigned char key, //The key that was pressed
	int x, int y) {    //The current mouse coordinates
	switch (key) {
	case 27: //Escape key
		exit(0); //Exit the program
	}
}

//Initializes 3D rendering
void initRendering() {
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective


//Called when the window is resized
	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
		(double)w / (double)h, //The width-to-height ratio
		1.0,                   //The near z clipping coordinate
		200.0);                //The far z clipping coordinate
}

//Draws the 3D scene
void drawScene() {
	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	/*
	glBegin(GL_LINES);
	glColor3f(0.08f, 0.3f, 0.7f);
	glVertex3f(3.0, 4.0, -5.0);
	glVertex3f(2.0, 3.0, -5.0);
	glEnd(); */
	
	//pentagon
	glBegin(GL_QUADS);
	glVertex3f(2.5f, 1.2f, -5.0f);
	glVertex3f(2.65f, 0.7f, -5.0f);
	glVertex3f(3.35f, 0.7f, -5.0f);
	glVertex3f(3.5f, 1.2f, -5.0f);
	glEnd(); //End quadrilateral coordinates

    
	glBegin(GL_TRIANGLES);
	glVertex3f(2.5f, 1.2f, -5.0f);
	glVertex3f(3.0f, 1.5f, -5.0f);
	glVertex3f(3.5, 1.2f, -5.0f);

	glEnd(); //End triangle coordinates

	//Hexagon
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 1.7f, -5.0f);
	glVertex3f(0.5f, 1.7f, -5.0f);
	glVertex3f(0.75f, 1.2f, -5.0f);
	glVertex3f(0.5f, 0.7f, -5.0f);
	glVertex3f(0.0f, 0.7f, -5.0f);
	glVertex3f(-0.25f, 1.2f, -5.0f);
	glEnd();

	//Heptagon
	glBegin(GL_POLYGON);
	glVertex3f(-2.3f, 1.19f, -5.0f); //A
	glVertex3f(-2.5f, 1.1f, -5.0f);  //B
	glVertex3f(-2.58f, 0.9f, -5.0f); //D
	glVertex3f(-2.43f, 0.7f, -5.0f); //F
	glVertex3f(-2.16f, 0.7f, -5.0f); //G
	glVertex3f(-2.02f, 0.9f, -5.0f); //E
	glVertex3f(-2.1f, 1.1f, -5.0f);  //C
	glEnd();

	//Octagon
	glBegin(GL_POLYGON);
	glVertex3f(2.48f,-0.6f, -5.0f); 
	glVertex3f(3.1f, -0.6f, -5.0f);  
	glVertex3f(3.4f, -0.96f, -5.0f); 
	glVertex3f(3.4f, -1.46f, -5.0f); 
	glVertex3f(3.08f, -1.8f, -5.0f); 
	glVertex3f(2.49f, -1.8f, -5.0f); 
	glVertex3f(2.2f,  -1.45f, -5.0f);  
	glVertex3f(2.2f,  -0.95f, -5.0f); 
	glEnd();
	
	//Nonagon
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, -0.56f, -5.0f); //I
	glVertex3f(0.4f, -0.68f, -5.0f); //j
	glVertex3f(0.8f, -1.0f, -5.0f);  //L
	glVertex3f(0.73f, -1.49f, -5.0f); //N
	glVertex3f(0.32f, -1.8f, -5.0f); //P
	glVertex3f(-0.32f, -1.8f, -5.0f); //Q
	glVertex3f(-0.74f, -1.51f, -5.0f); //O
	glVertex3f(-0.8f, -1.0f, -5.0f); //M
	glVertex3f(-0.4f, -0.67f, -5.0f); //K
	glEnd();
	
	//Decagon
	glBegin(GL_POLYGON);
	glVertex3f(-2.96f, -0.2f, -5.0f); //E
	glVertex3f(-2.25f, -0.2f, -5.0f); //H
	glVertex3f(-1.8f, -0.6f, -5.0f);  //B
	glVertex3f(-1.68f, -1.0f, -5.0f); //R
	glVertex3f(-1.79f, -1.48f, -5.0f); //F
	glVertex3f(-2.24f, -1.8f, -5.0f); //G
	glVertex3f(-2.97f, -1.8f, -5.0f); //A
	glVertex3f(-3.38f, -1.48f, -5.0f); //C
	glVertex3f(-3.54f, -1.0f, -5.0f); //D
	glVertex3f(-3.4f, -0.6f, -5.0f); //S
	glEnd();

	/*
	glBegin(GL_TRIANGLES); //Begin triangle coordinates

	//Pentagon
	glVertex3f(0.5f, 0.5f, -5.0f);
	glVertex3f(1.5f, 0.5f, -5.0f);
	glVertex3f(0.5f, 1.0f, -5.0f);

	glVertex3f(0.5f, 1.0f, -5.0f);
	glVertex3f(1.5f, 0.5f, -5.0f);
	glVertex3f(1.5f, 1.0f, -5.0f);

	glVertex3f(0.5f, 1.0f, -5.0f);
	glVertex3f(1.5f, 1.0f, -5.0f);
	glVertex3f(1.0f, 1.5f, -5.0f);
	*/
	
	
	glutSwapBuffers(); //Send the 3D scene to the screen
}

int main(int argc, char** argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400); //Set the window size

	//Create the window
	glutCreateWindow("Basic Shapes - videotutorialsrock.com");
	initRendering(); //Initialize rendering

	//Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
	return 0; //This line is never reached
}
