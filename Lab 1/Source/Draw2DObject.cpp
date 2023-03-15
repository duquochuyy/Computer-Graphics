#include "Header.h"

void readData()
{
	ifstream fileIn("input.txt", ios::in);
	int code, x1, y1, x2, y2, xT, yT, r, p, a, b;

	if (fileIn.good()) {
		string str;
		while (getline(fileIn, str)) {
			istringstream ss(str);
			int code;
			ss >> code;
			switch (code)
			{
			case 0:
				ss >> x1 >> y1 >> x2 >> y2;
				getTime();
				// ve duong thang bang DDA
				lineDDA(x1, y1, x2, y2);
				
				cout << "Time draw Line " << "(" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ") with DDA : " << 1000.0 * stopTime() << " (ms)" << endl;
				break;
			case 1:
				ss >> x1 >> y1 >> x2 >> y2;
				getTime();
				// ve duong thang bang Bresenham
				lineBresenham(x1, y1, x2, y2);

				cout << "Time draw Line " << "(" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ") with Bresenham: " << 1000.0 * stopTime() << " (ms)" << endl;
				break;
			case 2:
				ss >> xT >> yT >> r;
				getTime();
				// ve hinh tron bang MidPoint
				circleMidPoint(xT, yT, r);

				cout << "Time draw Circle " << "(" << xT << ", " << yT << "), r = " << r << " with MidPoint : " << 1000.0 * stopTime() << " (ms)" << endl;
				break;
			case 3:
				ss >> xT >> yT >> a >> b;
				getTime();
				// ve hinh ellipse bang MidPoint
				ellipseMidPoint(xT, yT, a, b);

				cout << "Time draw Ellipse " << "(" << xT << ", " << yT << "), a = " << a << ", b = " << b << " with MidPoint : " << 1000.0 * stopTime() << " (ms)" << endl;
				break;
			case 4:
				ss >> xT >> yT >> p;
				getTime();
				// ve parabol bang MidPoint
				parabolMidPoint(xT, yT, p);

				cout << "Time draw Parabol " << "(" << xT << ", " << yT << "), p = " << p << " with MidPoint : " << 1000.0 * stopTime() << " (ms)" << endl;
				break;
			case 5:
				ss >> xT >> yT >> a >> b;
				getTime();
				// ve hyperbol bang MidPoint
				hyperbolMidPoint(xT, yT, a, b);

				cout << "Time draw Hyperbol " << "(" << xT << ", " << yT << "), a = " << a << ", b = " << b << " with MidPoint: " << 1000.0 * stopTime() << " (ms)" << endl;
				break;
			default:
				break;
			}
			glFlush();
		}
	}

	fileIn.close();
	
	// demo
	/*parabolMidPoint(300, 100, 50);
	circleMidPoint(150, 350, 50);
	circleMidPoint(450, 350, 50);
	lineDDA(300, 150, 250, 200);
	lineBresenham(300, 150, 350, 200);
	ellipseMidPoint(300, 250, 20, 30);
	hyperbolMidPoint(300, 120, 60, 100);
	hyperbolMidPoint(300, 250, 177, 60);*/
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);
	       
	readData();

	// so sanh voi ham do OpenGL cung cap
	/*cout << "---------------------------\n\n\n\nDraw Object OpenGL\n";
	drawObjectByOpenGL();*/

	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Draw_2D_Object");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
