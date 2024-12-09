#pragma once

#include "Event.h"

namespace Sapling
{
	class KeyEvent : public Event
	{
	public:
		unsigned int GetKeyCode() const { return _keyCode; }
		unsigned int GetScancode() const { return _scancode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(unsigned int keyCode, unsigned int scancode)
			: _keyCode(keyCode), _scancode(scancode) {}

		unsigned int _keyCode;
		unsigned int _scancode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(unsigned int keyCode, unsigned int scancode)
			: KeyEvent(keyCode, scancode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << _keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};

	class KeyRepeatedEvent : public KeyEvent
	{
	public:
		KeyRepeatedEvent(unsigned int keyCode, unsigned int scancode)
			: KeyEvent(keyCode, scancode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyRepeatedEvent: " << _keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyRepeated)
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(unsigned int keyCode, unsigned int scancode)
			: KeyEvent(keyCode, scancode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << _keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class CharEvent : public Event
	{
	public:
		unsigned int GetCodepoint() const { return _codepoint; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		CharEvent(unsigned int codepoint)
			: _codepoint(codepoint) {}

		unsigned int _codepoint;
	};

	class CharTypedEvent : public CharEvent
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

	class CharTypedWithModsEvent : public CharEvent
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
