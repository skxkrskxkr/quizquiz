#include "glfw3.h"
#include <algorithm>
#include <stdbool.h>
#include <math.h>

const int width = 1000;
const int height = 1000;

float* pixels = new float[width*height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}
int min(const int a, const int b)
{
	if (a > b)
		return b;
	if (a < b)
		return a;
	if (a == b)
		return a;
}
void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		int lines = abs(i - i0);
		int lines2 = abs(j1 - j0);
		int lines3 = abs(i1 - i0);
		const int j = (j1 - j0)*lines / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawcircle(const int x, const int y, const int r, const float& red, const float& green, const float& blue)
{
	int x_c = x;
	int y_c = y;


	for (int a = 0; a <= 2 * r; a++)
	{
		for (int b = 0; b <= 2 * r; b++)
		{
			int f = (r - b)*(r - b) + (r - a)*(r - a) - r*r;
			if (f < 0 && -200 < f)
			{
				drawPixel(x - r + b, y - r + a, 255, 0, 0);
			}
		}
	}
}

void emptylect(const int x, const int y, const int width, const int height, const float& red, const float& green, const float& blue)
{
	for (int a = 0; a <= width; a++)
	{
		drawPixel(x + a, y, 255, 0, 0);
		drawPixel(x + a, y - height, 255, 0, 0);

	}
	for (int a = 0; a <= height; a++)
	{
		drawPixel(x, y - a, 255, 0, 0);
		drawPixel(x + width, y - a, 255, 0, 0);
	}
}
void lect(const int x, const int y, const int width, const int height, const float& red, const float& green, const float& blue)
{
	for (int a = 0; a <= height; a++)
	{
		for (int b = 0; b <= width; b++)
		{
			drawPixel(x + b, y + a, red, green, blue);
		}
	}
}
int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		std::fill_n(pixels, width*height * 3, 1.0f);

		for (int a = 0; a < 5; a++)   // thick line
		{
			drawLine(10 + a, 670, 250 + a, 910, 255, 0, 0);
		}

		drawcircle(800, 250, 100, 255, 0, 0);

		emptylect(350, 900, 200, 200, 255, 0, 0);

		for (int a = 700; a < 900; a++)      // lect
			for (int b = 700; b < 900; b++)
			{
				drawPixel(b, a, 255, 0, 0);
			}

		drawLine(50, 200, 150, 300, 255, 0, 0);  // triangle
		drawLine(150, 300, 250, 200, 25, 0, 0);
		for (int a = 50; a < 250; a++)
		{
			drawPixel(a, 200, 255, 0, 0);
		}

		drawLine(350, 300, 450, 380, 255, 0, 0); // pentagon
		drawLine(450, 380, 550, 300, 255, 0, 0);
		drawLine(350, 300, 400, 200, 255, 0, 0);
		drawLine(500, 200, 550, 300, 255, 0, 0);
		for (int a = 400; a < 500; a++)
		{
			drawPixel(a, 200, 255, 0, 0);
		}
		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	delete[] pixels;

	glfwTerminate();
	return 0;
}