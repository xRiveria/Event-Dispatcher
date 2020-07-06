#pragma once
#include "EventSystemPrecompiledHeader.h"
#include "Event.h"

namespace EventSystem
{
	class KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }
		EVENT_CLASS_CATEGORY(EventCategoryInputEvent | EventCategoryKeyboardEvent)

	protected:
		KeyEvent(int keyCode) : m_KeyCode(keyCode) {}
		int m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{	
	public:
		KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), m_TimesPressed(repeatCount) {}
		inline int GetRepeatCount() const { return m_TimesPressed; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key Pressed (" << (char)m_KeyCode << ")" << ", Repeated For " << m_TimesPressed << " Times.";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_TimesPressed;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode){}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key Released (" << (char)m_KeyCode << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}