#include "EventSystemPrecompiledHeader.h"
#include "glfw3.h"
#include <iostream>
#include "MainWindow.h"

void activate_airship()
{
	std::cout << "Hello!" << std::endl;
	std::cin.get();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
		activate_airship();
}


int main()
{
	EventSystem::MainWindow::InitializeGLFW();
    EventSystem::MainWindow::CreateMainWindow("Event System", 1280, 1080);
	

	glfwSetKeyCallback(EventSystem::MainWindow::GetMainWindow(), key_callback);
	while (true)
	{
		glfwSwapBuffers(EventSystem::MainWindow::GetMainWindow());
		glfwPollEvents();
	}
}

