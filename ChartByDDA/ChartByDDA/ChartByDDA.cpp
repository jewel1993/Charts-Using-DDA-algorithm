#include<stdlib.h>
#include<iostream>
#include<GL/glut.h>
using namespace std;
int ch,n;
int value[100];
void menu(void);

void myinit(){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glViewport(0,0,499.0,499.0);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

void dda(int x1, int y1, int x2, int y2){
    int steps, dx=(x2-x1), dy=(y2-y1);
    float xInc,yInc,x=x1,y=y1;
    if(abs(dx)>abs(dy))
    steps=abs(dx);
    else
    steps=abs(dy);
    xInc=dx/(float)steps;
    yInc=dy/(float)steps;

    glBegin(GL_POINTS);
    {
        glVertex2d(x,y);
        for(int k=0;k<steps;k++)
        {
            x+=xInc;
            y+=yInc;
            glVertex2d(x,y);
        }
    }glEnd();
	glFlush();
}

void vbar(){
    int x=20, y=20, x1=20, y1=450;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	dda(x, y, x1, y1);
    dda(x, y, y1, x1);
	for(int k=0; k<n;k++){
		float r=0.0, g=0.1, b=0.5;
		x+=20;
		x1+=20;
			for(int j=0;j<=2;j++){
				y1=value[k];
				r+=0.3;
		for(int i=0;i<=10;i++){
			glColor3f(r, g, b);
		dda(x+10, y+3, x1+10, y1);
		x++;
		x1++;
	}
	}
	}
	glFlush();
	glutDisplayFunc(menu);
}

void vbar1()
{
	int x=20, y=20, x1=20, y1=450;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	dda(x, y, x1, y1);
	dda(x, y, y1, x1);
	float r=0.1, g=0.1, b=1.0;
	for(int k=0; k<n;k++){
		x+=20;
		x1+=20;
		y1=value[k];
		int l=20;
		r+=0.1;
		g+=0.2;
		b-=0.1;
		for(int i=0;i<=30;i++){
			glColor3f(r, g, b);
			dda(x+10, y+3, x1+10, y1);
			x++;
			x1++;
		}
	}
	glFlush();
	glutDisplayFunc(menu);
}
void hbar(){
    int x=20, y=20, x1=20, y1=450;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	dda(x, y, x1, y1);
    dda(x, y, y1, x1);
	for(int k=n-1; k>=0;k--){
		float r=0.1, g=0.1, b=0.5;
		y+=20;
		x1+=20;
		for(int j=0;j<=2;j++){
			y1=value[k];
			g+=0.3;
			for(int i=0;i<=10;i++){
				glColor3f(r, g, b);
				dda(x+3, y+10, y1, x1+10);
				y++;
				x1++;
			}
		}
	}
	glFlush();
	glutDisplayFunc(menu);
}

void line(){
    int x=20, y=20, x1=20, y1=450;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	glColor3f(0.0,0.0,0.0);
	dda(x, y, x1, y1);
    dda(x, y, y1, x1);
   	glPointSize(0.5);
    for(int i=0; i<=13; i++){
        y+=30;
        x1+=30;
      	dda(x, y, y1, x1);
    }
	float r=0.0,g=1.0,b=0.0;
	glPointSize(15);
	glLineWidth(5);
	if(n==1)
	{
		glBegin(GL_POINTS);
		glVertex2i(value[0]+40,value[0]+40);
		glEnd();
	}
	else
	{
		int k=1;
	for(int i=0;i<n-1;i++)
	{
		glColor3f(r,g,b);
		dda(x+60,value[i]+20,x+120,value[i+1]+20);
		r+=0.3;
		g-=0.2;
		b+=0.1;
		x+=60;
	}
	}
	glPointSize(5);
	glLineWidth(9);
	glFlush();
	glutDisplayFunc(menu);
}


void step(){
    int x=20, y=20, x1=20, y1=450;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	dda(x, y, x1, y1);
    dda(x, y, y1, x1);
    glPointSize(2.0);
	float r=0.0,g=1.0,b=0.0;
	for(int i=0;i<n;i++)
	{
		x1+=50;
		glColor3f(r,g,b);
		dda(x+1, y, x+1, value[i]);
		dda(x, value[i], x1, value[i]);
		dda(x1, value[i], x1, y);
		x=x1;
		r+=0.3;
		g-=0.2;
		b+=0.1;
	}
    glFlush();
	glutDisplayFunc(menu);
}

void scatter(){
    int x=20, y=20, x1=20, y1=450;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	dda(x, y, x1, y1);
    dda(x, y, y1, x1);
	glColor3f(1.0,0.4,0.2);
	dda(x, y, 450, 450);
   	glPointSize(0.5);
    for(int i=0; i<=13; i++){
        y+=30;
        x1+=30;
      	dda(x, y, y1, x1);
    }
	float r=0.0,g=1.0,b=0.0;
	glPointSize(15);
	glLineWidth(5);
	if(n==1)
	{
		glBegin(GL_POINTS);
		glVertex2i(value[0]+40,value[0]+40);
		glEnd();
	}
	else
	{
		int k=1;
		for(int i=0;i<n-1;i++)
		{
			glColor3f(r,g,b);
			glPointSize(15);
			glBegin(GL_POINTS);
			glVertex2i(x+60,value[i]+20);
			glVertex2i(x+120,value[i+1]+20);
			glEnd();
			glPointSize(5);
			dda(x+65,value[i]+20,x+115,value[i+1]+20);
			r+=0.3;
			g-=0.2;
			b+=0.1;
			x+=60;
		}
	}
	glPointSize(5);
	glLineWidth(9);
    glFlush();
	glutDisplayFunc(menu);
}


void menu(void)
{		
		level :
		cout<<"\n\n---------------------------------CHART PROGRAM---------------------------------------";
		cout<<"\n0. Enter the values\n\n\n";
		cout<<"\n\n------------------------------------Options---------------------------------------\n";
		cout<<"1. Verical bar graph\n2. Horizontal bar graph\n";
		cout<<"3. Multicolor vertical bar\n4. Line chart\n";
		cout<<"5. Scatter chart\n6. Step chart\n7. Exit\n\nEnter your choice  :  ";
		cin>>ch;
		switch(ch){
		case 0: cout<<"Enter the number of values : ";
				cin>>n;
				for(int k=0;k<n;k++)
				{
					cout<<"\nEnter ["<<k+1<<"] position Value :  ";
					cin>>value[k];
				}
				goto level;
		case 1:	glutDisplayFunc(vbar);
		        break;
		case 2: glutDisplayFunc(hbar);
		        break;
		case 3: glutDisplayFunc(vbar1);
		        break;
		case 4: glutDisplayFunc(line);
		        break;
		case 5: glutDisplayFunc(scatter);
		        break;
		case 6: glutDisplayFunc(step);
		        break;
		case 7: exit(0);
		default: cout<<"Invalid option\n";
		}
}

void main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(700, 0);
	glutCreateWindow("Charts using DDA");
	glutDisplayFunc(menu);
	myinit();
	glutMainLoop();
}
