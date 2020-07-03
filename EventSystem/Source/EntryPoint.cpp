#include "EventSystemPrecompiledHeader.h"
#include "glfw3.h"
#include <iostream>
#include "MainWindow.h"

int main()
{
	EventSystem::MainWindow::InitializeGLFW();
    EventSystem::MainWindow::CreateMainWindow("Event System", 1280, 1080);
	
	while (true)
	{

	}
}