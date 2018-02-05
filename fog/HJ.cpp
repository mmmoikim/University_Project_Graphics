

#include <stdio.h>
#include <windows.h>
#include <cmath>
#include <gl\glut.h>


	GLfloat lightpos1[4] = {50,100,0,1};
	GLfloat lightpos2[] = {20,100,20,1};
	GLfloat lightpos3[] = {-40,100,0,1};
	GLfloat lightpos4[] = {-100,300,50,1};


	GLfloat specular4[4]={0.3,0.3,0.3,1};
	GLfloat diffuse4[4]={0.5,0.5,0.5,1};
	GLfloat ambient4[4]={0.1,0.1,0.1,1};

	GLfloat fcolor[4] = {0.5,0.5,0.5,1};

//http://blog.naver.com/utez?Redirect=Log&logNo=90114232638

	GLfloat glass[][3] = 
{ 
	{-40.0, -0.1, -40}, // vertex 0
	{40.0, -0.1, -40}, // vertex 1
	{40.0, 0, -40}, // vertex 2
	{-40.0, 0, -40}, // vertex 3
	{-40.0, -0.1, 20}, // vertex 4
	{40.0, -0.1, 20}, // vertex 5
	{40.0, 0, 20}, // vertex 6
	{-40.0, 0, 20}, // vertex 7
};


GLfloat ben1[][3] = 
{
	{0, 20, 0}, // vertex 0
	{4, 20 , 0}, // vertex 1
	{4, 0, 0}, // vertex 2
	{0, 0, 0}, // vertex 3
	{0, 20, 4}, // vertex 4
	{4, 20, 4}, // vertex 5
	{4, 0, 4}, // vertex 6
	{0, 0, 4}, // vertex 7
};

GLfloat ben2[][3] = 
{
	{-0.5, 19, -0.5}, // vertex 0
	{4.5, 19 , -0.5}, // vertex 1
	{4.5,14, -0.5}, // vertex 2
	{-0.5, 14, -0.5}, // vertex 3
	{-0.5, 19, 4.5}, // vertex 4
	{4.5, 19, 4.5}, // vertex 5
	{4.5, 14, 4.5}, // vertex 6
	{-0.5, 14, 4.5}, // vertex 7
};
GLfloat ben3[][3] = 
{
	{0, 18.5, 4.5}, // vertex 0
	{4, 18.5 , 4.5}, // vertex 1
	{4, 14.5, 4.5}, // vertex 2
	{0, 14.5, 4.5}, // vertex 3
	{0, 18.5, 5.2}, // vertex 4
	{4, 18.5, 5.2}, // vertex 5
	{4, 14.5, 5.2}, // vertex 6
	{0, 14.5, 5.2}, // vertex 7
};
GLfloat ben4[][3] = 
{
	{2, 24, 2}, // vertex 0
	{2, 24 ,2}, // vertex 1
	{4, 20, 0}, // vertex 2
	{0, 20, 0}, // vertex 3
	{2, 24, 2}, // vertex 4
	{2, 24, 2}, // vertex 5
	{4, 20, 4}, // vertex 6
	{0, 20, 4}, // vertex 7
};
GLfloat ben5[][3] = 
{
	{1, 23.5, 1}, // vertex 0
	{3, 23.5 ,1}, // vertex 1
	{3, 22, 1}, // vertex 2
	{1, 22, 1}, // vertex 3
	{1, 23.5, 3}, // vertex 4
	{3, 23.5, 3}, // vertex 5
	{3, 22, 3}, // vertex 6
	{1, 22, 3}, // vertex 7
};

GLfloat ben6[][3] = 
{
	{2, 25, 2}, // vertex 0
	{2, 25 ,2}, // vertex 1
	{3, 23.5, 1}, // vertex 2
	{1, 23.5, 1}, // vertex 3
	{2, 25, 2}, // vertex 4
	{2, 25, 2}, // vertex 5
	{3, 23.5, 3}, // vertex 6
	{1, 23.5, 3}, // vertex 7
};
//////////////////////////////////////////////////////////////////////////////////////////빅벤

GLfloat colors[][3] = 

{ 

	{0.78,0.7,0.63},  //color 0
	{0.98,0.87,0.77},//color 1
	{0.98,0.87,0.77},  //color 2
	{0.98,0.87,0.77}, //color 3
	{0.78,0.7,0.63}, //color 4
	{0.98,0.87,0.77}, //color 5
	{0.98,0.87,0.77}, //color 6
	{0.98,0.87,0.77}  //color 7 

};


GLfloat matrix[100];

static int window_width = 700; //window size
static int window_height = 700;

bool leftmouseDown = false;
bool rightmouseDown = false;
bool middlemouseDown = false;

float xrot = 0.0f;
float yrot = 0.0f;

float mouseCurPositionX= 0.0f;
float mouseCurPositionY= 0.0f;

float xdiff = 0.0f;
float ydiff = 0.0f;

float scale = 1.0f;

float translationx = 0.0f;
float translationy = 0.0f;

float rot = 0.0f;

GLuint ben_wall;
GLuint ben_clock;
GLuint ben_roof;
GLuint ben_roof2;
GLuint ground;
GLuint temp;


GLfloat xAngle, yAngle, zAngle;

GLint EnvMode = GL_REPLACE;

GLint TexFilter = GL_LINEAR;


void Draw_Axis()

{
	glBegin(GL_LINES);
	//X-axis (red)
	glColor3f(20,0,0);
	glVertex3f(0,0,0);
	glVertex3f(20,0,0);
	//Y-axis (green)
	glColor3f(0,20,0);
	glVertex3f(0,0,0);
	glVertex3f(0,20,0);
	//Z-axis (blue)
	glColor3f(0,0,20);
	glVertex3f(0,0,0);
	glVertex3f(0,0,20);  
	glEnd();
}
void Bigben(int a, int b, int c, int d)
{
	///////////////////////1
	glBindTexture(GL_TEXTURE_2D,ben_wall);

	glBegin(GL_TRIANGLES);
	{
		
		 glTexCoord2f(1.0, 0.0);
		glVertex3fv(ben1[a]);
		 glTexCoord2f(0.0, 0.0);
		glVertex3fv(ben1[b]);
		 glTexCoord2f(0.0, 1.0);
		glVertex3fv(ben1[c]);
	}
	glEnd();
	glBegin(GL_TRIANGLES);
	{
		glTexCoord2f(1.0, 0.0);
		glVertex3fv(ben1[a]);
		glTexCoord2f(0.0, 1.0);
		glVertex3fv(ben1[c]);
		glTexCoord2f(1.0, 1.0);
		glVertex3fv(ben1[d]);
	}
	glEnd();	

	/////////////////////////////////////////2
		glBindTexture(GL_TEXTURE_2D,ben_wall);

	glBegin(GL_TRIANGLES);
	{
		
		 glTexCoord2f(1.0, 0.0);
		glVertex3fv(ben2[a]);
		 glTexCoord2f(0.0, 0.0);
		glVertex3fv(ben2[b]);
		 glTexCoord2f(0.0, 1.0);
		glVertex3fv(ben2[c]);
	}
	glEnd();
	glBegin(GL_TRIANGLES);
	{
		glTexCoord2f(1.0, 0.0);
		glVertex3fv(ben2[a]);
		glTexCoord2f(0.0, 1.0);
		glVertex3fv(ben2[c]);
		glTexCoord2f(1.0, 1.0);
		glVertex3fv(ben2[d]);
	}
	glEnd();	
	//////////////////////////////////////3
glBindTexture(GL_TEXTURE_2D,ben_clock);

	glBegin(GL_TRIANGLES);
	{
		
		 glTexCoord2f(1.0, 0.0);
		glVertex3fv(ben3[a]);
		 glTexCoord2f(0.0, 0.0);
		glVertex3fv(ben3[b]);
		 glTexCoord2f(0.0, 1.0);
		glVertex3fv(ben3[c]);
	}
	glEnd();
	glBegin(GL_TRIANGLES);
	{
		glTexCoord2f(1.0, 0.0);
		glVertex3fv(ben3[a]);
		glTexCoord2f(0.0, 1.0);
		glVertex3fv(ben3[c]);
		glTexCoord2f(1.0, 1.0);
		glVertex3fv(ben3[d]);
	}
	glEnd();
		//////////////////////////////////////4
glBindTexture(GL_TEXTURE_2D,ben_roof);

	glBegin(GL_TRIANGLES);
	{
		
		 glTexCoord2f(1.0, 0.0);
		glVertex3fv(ben4[a]);
		 glTexCoord2f(0.0, 0.0);
		glVertex3fv(ben4[b]);
		 glTexCoord2f(0.0, 1.0);
		glVertex3fv(ben4[c]);
	}
	glEnd();
	glBegin(GL_TRIANGLES);
	{
		glTexCoord2f(1.0, 0.0);
		glVertex3fv(ben4[a]);
		glTexCoord2f(0.0, 1.0);
		glVertex3fv(ben4[c]);
		glTexCoord2f(1.0, 1.0);
		glVertex3fv(ben4[d]);
	}
	glEnd();
	////////////////////////////////5
			glBindTexture(GL_TEXTURE_2D,ben_roof2);

	glBegin(GL_TRIANGLES);
	{
		
		 glTexCoord2f(1.0, 0.0);
		glVertex3fv(ben5[a]);
		 glTexCoord2f(0.0, 0.0);
		glVertex3fv(ben5[b]);
		 glTexCoord2f(0.0, 1.0);
		glVertex3fv(ben5[c]);
	}
	glEnd();
	glBegin(GL_TRIANGLES);
	{
		glTexCoord2f(1.0, 0.0);
		glVertex3fv(ben5[a]);
		glTexCoord2f(0.0, 1.0);
		glVertex3fv(ben5[c]);
		glTexCoord2f(1.0, 1.0);
		glVertex3fv(ben5[d]);
	}
	glEnd();

	////////////////////6
				glBindTexture(GL_TEXTURE_2D,ben_roof);

	glBegin(GL_TRIANGLES);
	{
		
		 glTexCoord2f(1.0, 0.0);
		glVertex3fv(ben6[a]);
		 glTexCoord2f(0.0, 0.0);
		glVertex3fv(ben6[b]);
		 glTexCoord2f(0.0, 1.0);
		glVertex3fv(ben6[c]);
	}
	glEnd();
	glBegin(GL_TRIANGLES);
	{
		glTexCoord2f(1.0, 0.0);
		glVertex3fv(ben6[a]);
		glTexCoord2f(0.0, 1.0);
		glVertex3fv(ben6[c]);
		glTexCoord2f(1.0, 1.0);
		glVertex3fv(ben6[d]);
	}
	glEnd();


}

void polygon(int a, int b, int c , int d)

{
	
		////////////////////////////////ground
	glBindTexture(GL_TEXTURE_2D,ground);
	glBegin(GL_TRIANGLES);
	{
		
		 glTexCoord2f(1.0, 0.0);
		glVertex3fv(glass[a]);
		 glTexCoord2f(0.0, 0.0);
		glVertex3fv(glass[b]);
		 glTexCoord2f(0.0, 1.0);
		glVertex3fv(glass[c]);
	}
	glEnd();
	glBegin(GL_TRIANGLES);
	{
		glTexCoord2f(1.0, 0.0);
		glVertex3fv(glass[a]);
		glTexCoord2f(0.0, 1.0);
		glVertex3fv(glass[c]);
		glTexCoord2f(1.0, 1.0);
		glVertex3fv(glass[d]);
	}
	glEnd();


	glPushMatrix();
	glRotatef(-20,0,1, 0);
	glScalef(0.45,0.45,0.45);
	glTranslatef(0,0,17);
	Bigben(a,b,c,d);
	glPopMatrix();
		
	
}

void colorcube()
{
	polygon(4,5,6,7);
	polygon(0,1,2,3);
	polygon(5,1,2,6);
	polygon(0,4,7,3);
	polygon(7,6,2,3);
	polygon(4,5,1,0);
}


GLubyte *LoadBmp(const char *Path, int *Width, int *Height)

{

     HANDLE hFile;

     DWORD FileSize, dwRead;

     BITMAPFILEHEADER *fh=NULL;

     BITMAPINFOHEADER *ih;

     BYTE *pRaster;

 

     hFile=CreateFileA(Path,GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);

     if (hFile==INVALID_HANDLE_VALUE) {

          return NULL;

     }

 

     FileSize=GetFileSize(hFile,NULL);

     fh=(BITMAPFILEHEADER *)malloc(FileSize);

     ReadFile(hFile,fh,FileSize,&dwRead,NULL);

     CloseHandle(hFile);

 

     int len = FileSize - fh->bfOffBits;

     pRaster=(GLubyte *)malloc(len);

     memcpy(pRaster, (BYTE *)fh+fh->bfOffBits, len);

 

     // RGB로 순서를 바꾼다.

     for (BYTE *p=pRaster;p < pRaster + len - 3;p+=3) {

          BYTE b = *p;

          *p = *(p+2);

          *(p+2) = b;

     }

 

     ih=(BITMAPINFOHEADER *)((PBYTE)fh+sizeof(BITMAPFILEHEADER));

     *Width=ih->biWidth;

     *Height=ih->biHeight;

 

     free(fh);

     return pRaster;

}
void display()

{
 
	 glShadeModel(GL_SMOOTH);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_COLOR_MATERIAL);

	glPushMatrix();
	 
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glScalef(scale,scale,scale);
	glTranslatef(translationx,translationy,0);
	colorcube();
//	Draw_Axis();
	glPopMatrix();

	glFlush();

	glutSwapBuffers();

}


void reshape(int w, int h)

{

	glClearColor(1,1,1, 1);
	glViewport(0, 0, w, h);
	window_width = w;
	window_height = h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(w<=h) 
	{
		
		//glOrtho(-20, 20 , -20.0 * (GLfloat) h/ (GLfloat) w , 20.0* (GLfloat) h / (GLfloat) w, 1 , 20);
		gluPerspective(110.0f, 1.2f * w / h, 1.0f, 100.0f);
	}
	else
	{
		
		//glOrtho(-20, 20 , -20.0 * (GLfloat) h/ (GLfloat) w , 20.0* (GLfloat) h / (GLfloat) w, 1 , 20);
		gluPerspective(110.0f, 1.2f * w / h, 1.0f, 40.0f);
	}
	
	glTranslatef(0,0,-22);


	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	glGetFloatv(GL_MODELVIEW_MATRIX,matrix);

}

void idleFunc()

{
	
	rot = rot + 0.6;
	glutPostRedisplay();

}

void texture()
{
	GLubyte *data;
     int Width, Height;

	  // 텍스처 이미지 준비
     glEnable(GL_TEXTURE_2D);
	
	  glGenTextures(1,&ground);
	 glBindTexture(GL_TEXTURE_2D,ground);
     data = LoadBmp("glass.bmp", &Width, &Height);
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB,  GL_UNSIGNED_BYTE, data);
     free(data);
     glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


	 
	 glGenTextures(1,&ben_roof2);
	 glBindTexture(GL_TEXTURE_2D,ben_roof2);
     data = LoadBmp("ben_roof2.bmp", &Width, &Height);
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB,  GL_UNSIGNED_BYTE, data);
     free(data);
     glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);



	 glGenTextures(1,&ben_roof);
	 glBindTexture(GL_TEXTURE_2D,ben_roof);
     data = LoadBmp("ben_roof.bmp", &Width, &Height);
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB,  GL_UNSIGNED_BYTE, data);
     free(data);
     glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	 glGenTextures(1,&ben_clock);
	 glBindTexture(GL_TEXTURE_2D,ben_clock);
     data = LoadBmp("ben_clock.bmp", &Width, &Height);
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB,  GL_UNSIGNED_BYTE, data);
     free(data);
     glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


	 glGenTextures(1,&ben_wall);
	 glBindTexture(GL_TEXTURE_2D,ben_wall);
     data = LoadBmp("ben_wall.bmp", &Width, &Height);
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB,  GL_UNSIGNED_BYTE, data);
     free(data);
     glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

}
void keyFunc(unsigned char key, int x, int y)

{

	switch(key)

	{

	case 'n' : 
	
	glEnable(GL_FOG);
	glFogf(GL_FOG_MODE, GL_EXP);
	glFogf(GL_FOG_START, -10.0f);
glFogf(GL_FOG_END, 50.0f);
glFogf(GL_FOG_DENSITY, 0.1);
glFogfv(GL_FOG_COLOR, fcolor);


	
		break;

	case 'f' :
	glDisable(GL_FOG);
		break;

	}


}


void init()

{

	glEnable(GL_DEPTH_TEST);

	
	//  glEnable(GL_LIGHTING);
	  glEnable(GL_LIGHT4);

	

	glLightfv(GL_LIGHT4, GL_AMBIENT,ambient4);
	glLightfv(GL_LIGHT4, GL_POSITION,lightpos4);
	glLightfv(GL_LIGHT4, GL_DIFFUSE,diffuse4);
	glLightfv(GL_LIGHT4, GL_SPECULAR,specular4);



}


void mouse(int button, int state, int x, int y)
{
	
if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
leftmouseDown = true;

xdiff = x - yrot;
ydiff = -y + xrot;
}
else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
{
leftmouseDown = false;
}

else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
{
rightmouseDown = true;
}
else if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
{
rightmouseDown = false;
}
else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
{
middlemouseDown = true;
}
else if(button == GLUT_MIDDLE_BUTTON && state == GLUT_UP)
{
middlemouseDown = false;
}
mouseCurPositionX = x;
mouseCurPositionY = y;

}

void mouseMotion(int x, int y)
{
if (leftmouseDown)
{
yrot = x - xdiff;
xrot = y + ydiff;
}

else if (rightmouseDown)
{
scale += (y-mouseCurPositionY)/100;
mouseCurPositionX = x;
mouseCurPositionY = y;
}

else if (middlemouseDown)
{
translationx += (x-mouseCurPositionX)/10;
translationy += (mouseCurPositionY-y)/10;
mouseCurPositionX = x;
mouseCurPositionY = y;
}

glutPostRedisplay();

}

int main(int argc, char **argv)

{

	glutInit(&argc, argv);

	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

	glutInitWindowSize( window_width, window_height );

	glutCreateWindow("3D Graphics");

	init();

	glutDisplayFunc( display );
	texture();
	glutMouseFunc(mouse);
   glutMotionFunc(mouseMotion);

	glutReshapeFunc(reshape);

	glutIdleFunc(idleFunc);

	glutKeyboardFunc( keyFunc );


	glutMainLoop();

	return 0;

}

