#pragma once

#include "Event.h"

#include <string>
#include <iosfwd>

namespace Pluto
{
	/**
	 * @brief Base key event class.
	 */
	class PLUTO_API KeyEvent : public Event
	{
	public:
		/**
		 * @brief Get the key code of the pressed button.
		 * @return Key code identifier of the pressed button.
		 */
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(int keyCode) : m_KeyCode(keyCode)
		{ }

		/** @brief Key code identifier of the button that was pressed. */
		int m_KeyCode;
	};

	/**
	 * @brief Key pressed event.
	 */
	class PLUTO_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount)
			: KeyEvent(keyCode), m_RepeatCount(repeatCount)
		{ }

		/**
		 * @brief Get count of repeats.
		 * @return Total count of repeats.
		 */
		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		/** @brief Total count of repeats. */
		int m_RepeatCount;
	};

	/**
	 * @brief Key released event.
	 */
	class PLUTO_API KeyReleased : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode)
			: KeyEvent(keyCode)
		{ }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}