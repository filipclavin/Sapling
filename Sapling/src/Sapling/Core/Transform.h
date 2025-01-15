#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace Sapling
{
	struct Transform
	{
	public:
		glm::vec3 _position;
		glm::quat _rotation;
		glm::vec3 _scale;

		Transform(const glm::vec3& position = { 0.0f, 0.0f, 0.0f },
				  const glm::quat& rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
				  const glm::vec3& scale = { 1.0f, 1.0f, 1.0f })
			: _position(position), _rotation(rotation), _scale(scale) {}

		operator glm::mat4() const;

		glm::mat4 GetMat4() const { return (glm::mat4)*this; }

		void Rotate(const glm::quat& rotation);
		void Rotate(float angle, const glm::vec3& axis);
		void RotateX(float angle);
		void RotateY(float angle);
		void RotateZ(float angle);

		void Reset();
	};
}