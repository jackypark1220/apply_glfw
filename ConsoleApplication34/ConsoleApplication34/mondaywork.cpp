#define d_SCL_SECURE_NO_WARNINGS
#include <glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"
#include<algorithm>
#include<Windows.h>

const int width = 1180;
const int height = 490;

float* pixels = new float[width*height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}



void drawOnPixelBuffer()
{
	fflush(stdin);
	//std::memset(pixels, 1.0f, sizeof(float)*width*height * 3); // doesn't work
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

													//for (int i = 0; i<width*height; i++) {
													//	pixels[i * 3 + 0] = 1.0f; // red 
													//	pixels[i * 3 + 1] = 1.0f; // green
													//	pixels[i * 3 + 2] = 1.0f; // blue
													//}

	const int i = rand() % width, j = rand() % height;
	//drawPixel(i, j, 0.0f, 0.0f, 0.0f);

	// drawing a line
	//TODO: anti-aliasing
	const int i0 = 100, i1 = 200;
	const int j0 = 50, j1 = 80;
	//drawLine(i0, j0, i1, j1, 1.0f, 0.0f, 0.0f);

	//TODO: try moving object
	
	
	/*drawrectanful(850, 850, 100, 0, 0, 100);
	drawrectanline(250, 250, 100, 250, 0, 0);
	drawthick(500, 800, 700, 900, 0, 255, 255);
	drawtri(500, 100, 650, 400, 800, 100, 255, 0, 0);
	drawpenta(600, 550, 550, 650, 650, 720, 750, 650, 700, 550, 255, 0, 0);*/
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
		// while background

   
								 /* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{	
			
				
			
	
			/* Render here */

			//glClear(GL_COLOR_BUFFER_BIT);

			drawOnPixelBuffer();
			double xpos, ypos;
				glfwGetCursorPos(window, &xpos, &ypos);
				printf("%f, %f\n", xpos, ypos);

				
				
			//TODO: RGB struct
			//Make a pixel drawing function
			//Make a line drawing function

			glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);
			glClearColor(1, 1, 1, 1);
			/* Swap front and back buffers */
			glfwSwapBuffers(window);



			/* Poll for and process events */
			glfwPollEvents();

			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	

		glfwTerminate();

		delete[] pixels; // or you may reuse pixels array 

		return 0;
	
}