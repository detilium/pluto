#pragma once

#include "Pluto/Core.h"

#include <string>
#include <functional>

namespace Pluto
{
	/**
	 * @brief Definition of all possible event types.
	 */
	enum class EventType
	{
		None = 0,
		WindowsClose, WindowsResize, WindowFocus, WindowFocusLost, WindowClose,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	/**
	 * @brief Definition of all possible event categories.
	 */
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication   = BIT(0),
		EventCategoryInput         = BIT(1),
		EventCategoryKeyboard      = BIT(2),
		EventCategoryMouse         = BIT(3),
		EventCategoryMouseButton   = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType:##type; }\
                               virtual EventType GetEventType() cosnt override { return GetStaticType(); }\
                               virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	/**
	 * @brief Base event class.
	 */
	class PLUTO_API Event
	{
	public:
		/**
		 * @brief Get event type
		 * @see EventType
		 * @return Type of event.
		 */
		virtual EventType GetEventType() const = 0;

		/**
		 * @brief Get a string representation of the event.
		 * @return String representation of the event.
		 */
		virtual const char* GetName() const = 0;

		/**
		 * @brief Get all category flags.
		 * @see EventCategory
		 * @return Category flags on the event.
		 */
		virtual int GetCategoryFlags() const = 0;

		virtual std::string ToString() const { return GetName(); }

		/**
		 * @brief Check whether the event is in the given category.
		 * @param category Category to check against.
		 * @return true if event is in category, false otherwise.
		 */
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		/** @brief Defines whether the event has been handled. */
		bool m_handled = false;
	};

	/**
	 * @brief Event dispatcher.
	 */
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{ }

		/**
		 * @brief Dispatch the event.
		 * @tparam T Event to dispatch.
		 * @param func Function to run on dispatch.
		 * @return true if WHAT???, false otherwise.
		 */
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetStaticType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_event);
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