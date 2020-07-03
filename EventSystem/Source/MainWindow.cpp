#include "EventSystemPrecompiledHeader.h"
#include "MainWindow.h"


namespace EventSystem
{
	GLFWwindow* MainWindow::m_ApplicationWindow = 0;

	const void MainWindow::CreateMainWindow(std::string windowName, int windowWidth, int windowHeight)
	{
		m_ApplicationWindow = glfwCreateWindow(windowWidth, windowHeight, windowName.c_str(), NULL, NULL);

		if (!m_ApplicationWindow)
		{
			EVENT_SYSTEM_ASSERT("Failed Window Creation!");
		}
		else
		{
			EVENT_SYSTEM_ASSERT("Window Creation Successful!");
		}
	}

	MainWindow::~MainWindow()
	{
		glfwDestroyWindow(m_ApplicationWindow);
	}

	const void MainWindow::InitializeGLFW()
	{
		if (!glfwInit())
		{
			EVENT_SYSTEM_ASSERT("Failed GLFW Initialization!");
		}
		else
		{
			EVENT_SYSTEM_ASSERT("Successful GLFW Initialization");
		}
	}
}