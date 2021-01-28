#include<GL/freeglut.h>
#include<math.h>

int width = 600;
int height = 600;

void display()
{
	int N = 20;
	double pi = 3.141592653;

	glViewport(0, 0, width, height);

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/*const float half_width = 1.0 * float(width) / float(height);
	const float half_height = 1.0 * float(height) / float(height);
	glOrtho(-half_height, half_width, -half_height, half_height, -1.0, 100.0);*/

	int i = 0;
	for (i = 1; i <= N; i++) {
		glBegin(GL_TRIANGLES);

		double p = (double)N / 3;
		double m = (double)3 * i / N;

		if (i <= p) {
			glColor4f(1.0 - m, m, 0.0, 0.7);
		}
		else if ((i > p) && (i <= 2 * p)) {
			glColor4f(0.0, 2.0 - m, -1.0 + m, 0.7);
		}
		else if ((i > 2 * p) && (i <= N)) {
			glColor4f(-2.0 + m, 0.0, 3.0 - m, 0.7);
		}

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(cos(2 * pi / N * (i - 1)), sin(2 * pi / N * (i - 1)), 0.0);
		glVertex3f(cos(2 * pi / N * i), sin(2 * pi / N * i), 0.0);

		glEnd();

		glEnable(GL_LINE_WIDTH);
		glLineWidth(3.0);

		glBegin(GL_LINES);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(cos(2 * pi / N * (i - 1)), sin(2 * pi / N * (i - 1)), 0.0);

		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(cos(2 * pi / N * i), sin(2 * pi / N * i), 0.0);

		glColor3f(0.0, 0.0, 0.0);

		glVertex3f(cos(2 * pi / N * (i - 1)), sin(2 * pi / N * (i - 1)), 0.0);
		glVertex3f(cos(2 * pi / N * i), sin(2 * pi / N * i), 0.0);

		glEnd();
	}

	glutSwapBuffers();
}

void resize(int w, int h)
{
	width = w;
	height = h;
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(width, height);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutCreateWindow("Hello world!");

	glutDisplayFunc(display);
	glutReshapeFunc(resize);

	glutMainLoop();

	return 0;
}