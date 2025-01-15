#include <sappch.h>
#include "Transform.h"

#include <Sapling/Renderer/RendererAPI.h>

namespace Sapling
{
	Transform::operator glm::mat4() const
	{
		return glm::mat4(1.0) *
			   glm::translate(glm::mat4(1.0f), _position) *
			   glm::mat4_cast(_rotation) *
			   glm::scale(glm::mat4(1.0f), _scale);
	}

	void Transform::Rotate(const glm::quat& rotation)
	{
		_rotation *= rotation;
	}
	void Transform::Rotate(float angle, const glm::vec3& axis)
	{
		Rotate(glm::angleAxis(angle, axis));
	}
	void Transform::RotateX(float angle)
	{
		Rotate(angle, glm::vec3(1.0f, 0.0f, 0.0f));
	}
	void Transform::RotateY(float angle)
	{
		Rotate(angle, glm::vec3(0.0f, 1.0f, 0.0f));
	}
	void Transform::RotateZ(float angle)
	{
		Rotate(angle, glm::vec3(0.0f, 0.0f, 1.0f));
	}

	void Transform::Reset()
	{
		_position = { 0.0f, 0.0f, 0.0f };
		_rotation = { 1.0f, 0.0f, 0.0f, 0.0f };
		_scale = { 1.0f, 1.0f, 1.0f };
	}
}