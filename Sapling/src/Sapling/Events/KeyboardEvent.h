#pragma once

#include "Event.h"
#include "Sapling/Core/KeyCodes.h"

namespace Sapling
{
	class KeyEvent : public Event
	{
	public:
		KEY GetKeyCode() const { return _keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(KEY keyCode)
			: _keyCode(keyCode) {}

		KEY _keyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(KEY keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << GetKeyName(_keyCode);
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};

	class KeyRepeatedEvent : public KeyEvent
	{
	public:
		KeyRepeatedEvent(KEY keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyRepeatedEvent: " << GetKeyName(_keyCode);
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyRepeated)
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(KEY keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << GetKeyName(_keyCode);
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class CharTypedEvent : public Event
	{
	public:
		CharTypedEvent(unsigned int codepoint)
			: _codepoint(codepoint) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "CharTypedEvent: " << (char)_codepoint;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
		EVENT_CLASS_TYPE(CharTyped)

	private:
		unsigned int _codepoint;
	};
	
}
