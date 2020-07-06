#pragma once
#include "EventSystemPrecompiledHeader.h"
#include "Events/Event.h"
#include "glfw3.h"

namespace EventSystem
{ 
	class MainWindow
	{
	public:
		static const void CreateMainWindow(std::string windowName, int windowWidth, int windowHeight);
		~MainWindow();

		static const void InitializeGLFW();
		static const void SetupEventCallbacks();
		static void OnEvent(Event& event);
		static GLFWwindow* GetMainWindow() { return m_ApplicationWindow; }
		//Events
		using EventCallbackfn = std::function<void(Event&)>;
		static void SetEventCallback(const EventCallbackfn& callback)
		{
			m_EventCallback = callback;
		}

	private:	
		static GLFWwindow* m_ApplicationWindow;
		static EventCallbackfn m_EventCallback;
	};
}