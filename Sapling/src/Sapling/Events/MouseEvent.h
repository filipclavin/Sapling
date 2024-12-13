#pragma once

#include "Event.h"
#include "Sapling/Core/MouseButtonCodes.h"

#include <glm/vec2.hpp>

namespace Sapling
{
	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(glm::vec2 mousePos)
			: _mousePos(mousePos) {}

		glm::vec2 GetPosition() const { return _mousePos; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << _mousePos.x << ", " << _mousePos.y;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		glm::vec2 _mousePos;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(glm::vec2 offset)
			: _offset(offset) {}

		glm::vec2 GetOffset() const { return _offset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << _offset.x << ", " << _offset.y;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		glm::vec2 _offset;
	};

	class MouseButtonEvent : public Event
	{
	public:
		MOUSE_BTN GetMouseButton() const { return _button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		MouseButtonEvent(MOUSE_BTN button)
			: _button(button) {}

		MOUSE_BTN _button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(MOUSE_BTN button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << GetMouseButtonName(_button);
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(MOUSE_BTN button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << GetMouseButtonName(_button);
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
