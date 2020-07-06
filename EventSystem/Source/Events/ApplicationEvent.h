#pragma once
#include "EventSystemPrecompiledHeader.h"
#include "Event.h"

//Close, Resize
namespace EventSystem
{
	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int windowWidth, unsigned int windowHeight) : m_WindowWidth(windowWidth), m_WindowHeight(windowHeight) {}
		inline unsigned int GetWindowWidth() const { return m_WindowWidth; }
		inline unsigned int GetWindowHeight() const { return m_WindowHeight; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Window Resize Event (" << m_WindowWidth << "x" << m_WindowHeight << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResized)
		EVENT_CLASS_CATEGORY(EventCategoryApplicationEvent)
								

	private:
		unsigned int m_WindowWidth, m_WindowHeight;
	};

	class WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent() {}
		EVENT_CLASS_TYPE(WindowClosed)
		EVENT_CLASS_CATEGORY(EventCategoryApplicationEvent)
	};
}




