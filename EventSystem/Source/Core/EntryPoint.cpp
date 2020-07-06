#include "EventSystemPrecompiledHeader.h"
#include "glfw3.h"
#include "../MainWindow.h"

//Entry point into the program itself. 

	int main()
	{
		EventSystem::MainWindow::InitializeGLFW();
		EventSystem::MainWindow::CreateMainWindow("Event System", 1280, 1080);
		EventSystem::MainWindow::SetupEventCallbacks();

		while (!glfwWindowShouldClose(EventSystem::MainWindow::GetMainWindow()))
		{
			glfwSwapBuffers(EventSystem::MainWindow::GetMainWindow());
			glfwPollEvents();
		}
	}


