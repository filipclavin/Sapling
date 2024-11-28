#pragma once

#include "Event.h"

namespace Sapling
{
	class SAPLING_API KeyEvent : public Event
	{
	public:
		KeyCode GetKeyCode() const { return _keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

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

	class SAPLING_API KeyRepeatedEvent : public KeyEvent
	{
	public:
		KeyRepeatedEvent(KeyCode keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyRepeatedEvent: " << _keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyRepeated)
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

	class SAPLING_API CharEvent : public Event
	{
	public:
		unsigned int GetCodepoint() const { return _codepoint; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		CharEvent(unsigned int codepoint)
			: _codepoint(codepoint) {}

		unsigned int _codepoint;
	};

	class SAPLING_API CharTypedEvent : public CharEvent
	{
	public:
		CharTypedEvent(unsigned int codepoint)
			: CharEvent(codepoint) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "CharTypedEvent: " << _codepoint;
			return ss.str();
		}

		EVENT_CLASS_TYPE(CharTyped)
	};

	class SAPLING_API CharTypedWithModsEvent : public CharEvent
	{
	public:
		CharTypedWithModsEvent(unsigned int codepoint, int mods)
			: CharEvent(codepoint), _mods(mods) {}

		int GetMods() const { return _mods; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "CharTypedWithModsEvent: " << _codepoint << " with mods: " << _mods;
			return ss.str();
		}

		EVENT_CLASS_TYPE(CharTypedWithMods)

	private:
		int _mods;
	};
	
}
