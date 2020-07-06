#pragma once
#include "EventSystemPrecompiledHeader.h"
#include "Event.h"

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
			ss << "Mouse Moved (" << m_MouseX << ", " << m_MouseY << ")";
			return ss.str();  //ss.str() converts from stringstream to a string itself. 
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryInputEvent | EventCategoryMouseEvent)

	private:
		float m_MouseX, m_MouseY;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : m_xOffset(xOffset), m_yOffset(yOffset) {}
		inline float GetXOffset() const { return m_xOffset; }
		inline float GetYOffset() const { return m_yOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Scrolled (" << m_xOffset << ", " << m_yOffset << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryInputEvent | EventCategoryMouseEvent)

	protected:
		float m_xOffset, m_yOffset;
	};

	class MouseButtonEvent: public Event
	{
	public:
		inline int GetMouseButton() const { return m_MouseButton; }
		EVENT_CLASS_CATEGORY(EventCategoryMouseEvent | EventCategoryInputEvent)

	protected:	
		MouseButtonEvent(int mouseButton) : m_MouseButton(mouseButton) {}
		int m_MouseButton;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int buttonPressed) : MouseButtonEvent(buttonPressed) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Pressed!";
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int buttonReleased) : MouseButtonEvent(buttonReleased) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Released!";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
