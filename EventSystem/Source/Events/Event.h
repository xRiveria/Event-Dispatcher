#pragma once
#include <string>

namespace EventSystem
{
	enum EventType
	{
		None = 0,
		MouseScrolled = 1,
		MouseMoved = 2,
		MouseButtonPressed = 3,
		MouseButtonReleased = 4,
		KeyPressed,
		KeyReleased,
		KeyTyped
	};

	enum EventTypeCategory
	{
		None = 0,
		EventCategoryMouseEvent = 1,
		EventCategoryKeyboardEvent = 2,
	};

	class Event
	{
	public:
		virtual EventType GetEventType() = 0;
		virtual std::string ToString() const = 0;
	};
}

