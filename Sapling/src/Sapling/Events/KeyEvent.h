#pragma once

#include "Event.h"

namespace Sapling
{
	class SAPLING_API KeyEvent : public Event
	{
	public:
		KeyCode GetKeyCode() const { return _keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard, EventCategoryInput)

	protected:
		KeyEvent(KeyCode keyCode)
			: _keyCode(keyCode) {}

		KeyCode _keyCode;
	};

	class SAPLING_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(KeyCode keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << _keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};

	class SAPLING_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(KeyCode keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << _keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
	
}
