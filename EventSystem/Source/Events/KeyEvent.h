#pragma once
#include "Event.h"
#include <sstream>

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
		KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), m_TimesPressed(repeatCount) {}
		inline int GetRepeatCount() const { return m_TimesPressed; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key Pressed Event: " << m_KeyCode << " Repeated For " << m_TimesPressed << " Times!";
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
			ss << "Key Released Event: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased);
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keyCode) : KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss; //Prints a string value.
			ss << "Key Typed Event: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped);
	};
}