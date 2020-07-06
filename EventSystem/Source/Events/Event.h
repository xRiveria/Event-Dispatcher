#pragma once
#include "EventSystemPrecompiledHeader.h"

namespace EventSystem
{
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
	
	enum class EventType
	{
		None = 0,
		MouseScrolled = 1,
		MouseMoved = 2,
		MouseButtonPressed = 3,
		MouseButtonReleased = 4,
		KeyPressed = 5,
		KeyReleased = 6,
		KeyTyped = 7,
		WindowClosed = 8,
		WindowResized = 9
	};

	enum EventTypeCategory
	{
		None = 0,
		EventCategoryMouseEvent = 1,
		EventCategoryKeyboardEvent = 2,
		EventCategoryInputEvent = 3,
		EventCategoryApplicationEvent = 4
	};

	class Event
	{
	public:
		bool hasEventBeenHandled = false;

		virtual EventType GetEventType() const = 0;
		virtual std::string ToString() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

		inline bool IsInCategory(EventTypeCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event) : m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.hasEventBeenHandled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}

