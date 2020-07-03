#pragma once
#include "EventSystemPrecompiledHeader.h"
#include "glfw3.h"

namespace EventSystem
{ 
	class MainWindow
	{
	public:
		static const void CreateMainWindow(std::string windowName, int windowWidth, int windowHeight);
		~MainWindow();

		static const void InitializeGLFW();
		static const GLFWwindow* GetMainWindow() { return m_ApplicationWindow; }

	private:
		static GLFWwindow* m_ApplicationWindow;
	};
}