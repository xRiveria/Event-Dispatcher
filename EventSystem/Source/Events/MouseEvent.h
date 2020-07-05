#pragma once
#include "Event.h"
#include <sstream>

namespace EventSystem
{
	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Moved Event: " << m_MouseX << m_MouseY;
			return ss.str();
		}

	private:
		float m_MouseX, m_MouseY;
	};


	class MouseButtonEvent: Event
	{
	public:
		inline int GetMouseButton() const { return m_MouseButton; }
		EVENT_CLASS_CATEGORY(EventCategoryMouseEvent | EventCategoryInputEvent)

	protected:	
		MouseButtonEvent(int mouseButton) : m_MouseButton(mouseButton) {}
		int m_MouseButton;
	};


	class MouseButtonPressedEvent : MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int buttonPressed) : MouseButtonEvent(buttonPressed) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Pressed Event";
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};


	class MouseButtonReleasedEvent : MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int buttonReleased) : MouseButtonEvent(buttonReleased) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Released Event";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
