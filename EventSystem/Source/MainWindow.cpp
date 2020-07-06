#include "EventSystemPrecompiledHeader.h"
#include "MainWindow.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

namespace EventSystem
{
    #define BIND_EVENT_FN(x) std::bind(&MainWindow::x, std::placeholders::_1)

	//Static Definitions
	GLFWwindow* MainWindow::m_ApplicationWindow = 0;
	MainWindow::EventCallbackfn MainWindow::m_EventCallback = 0;


	const void MainWindow::CreateMainWindow(std::string windowName, int windowWidth, int windowHeight)
	{
		m_ApplicationWindow = glfwCreateWindow(windowWidth, windowHeight, windowName.c_str(), NULL, NULL);
		
		SetEventCallback(BIND_EVENT_FN(OnEvent));

		if (!m_ApplicationWindow)
		{
			EVENT_SYSTEM_SUCCESS("Failed Window Creation!");
		}
		else
		{
			EVENT_SYSTEM_SUCCESS("Window Creation Successful!");
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

	const void MainWindow::SetupEventCallbacks()
	{
		glfwSetWindowSizeCallback(m_ApplicationWindow, [](GLFWwindow* window, int width, int height)
		{
			WindowResizeEvent event(width, height);
			m_EventCallback(event);
		});
		
		glfwSetWindowCloseCallback(m_ApplicationWindow, [](GLFWwindow* window)
		{
			WindowClosedEvent event();
			glfwSetWindowShouldClose(m_ApplicationWindow, GLFW_TRUE);
		});

		glfwSetKeyCallback(m_ApplicationWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					m_EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					m_EventCallback(event);
					break;
				}

				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					m_EventCallback(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_ApplicationWindow, [](GLFWwindow* window, int button, int action, int mods)
		{
			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					m_EventCallback(event);
					break;
				}

				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					m_EventCallback(event);
					break;
				}
			}		
		});

		glfwSetScrollCallback(m_ApplicationWindow, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			m_EventCallback(event);
		});

		glfwSetCursorPosCallback(m_ApplicationWindow, [](GLFWwindow* window, double xPosition, double yPosition)
		{
			MouseMovedEvent event((float)xPosition, (float)yPosition);
			m_EventCallback(event);
		});

	}
	void MainWindow::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		EVENT_SYSTEM_ASSERT(event);
	}
}