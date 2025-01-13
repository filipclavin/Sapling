#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace Sapling
{
	class Camera
	{
	public:
		const glm::mat4& GetProjectionMatrix() const { return _projectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return _viewMatrix; }
		const glm::mat4& GetViewProjectionMatrix() const { return _viewProjectionMatrix; }

		void SetProjectionMatrix(const glm::mat4& projectionMatrix);
		void SetViewMatrix(const glm::mat4& viewMatrix);

		const glm::vec3& GetPosition() const { return _position; }
		const glm::quat& GetRotation() const { return _rotation; }

		void SetPosition(const glm::vec3& position);
		void SetRotation(const glm::quat& rotation);

		float GetAspectRatio() const { return _aspectRatio; }

	private:
		void RecalculateViewMatrix();

	protected:
		Camera(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix, float aspectRatio, glm::vec3 position, glm::quat rotation);

		float _aspectRatio;

		glm::mat4 _projectionMatrix;
		glm::mat4 _viewMatrix;
		glm::mat4 _viewProjectionMatrix;

		glm::vec3 _position = { 0.0f, 0.0f, 0.0f };
		glm::quat _rotation = { 1.0f, 0.0f, 0.0f, 0.0f };
	};

	class OrthographicCamera : public Camera
	{
	public:
		OrthographicCamera(float aspectRatio = 16.0f / 9.0f,
						   float zoomLevel = 1.0f,
						   glm::vec3 position	= glm::vec3(),
						   glm::quat rotation	= glm::quat())
			: Camera(glm::ortho(-aspectRatio * zoomLevel, aspectRatio* zoomLevel, -zoomLevel, zoomLevel), glm::mat4(1.0f), aspectRatio, position, rotation),
			  _zoomLevel(zoomLevel) {}

		void SetOrthoProjection(float aspectRatio, float zoomLevel);

		void SetAspectRatio(float aspectRatio);

		float GetZoomLevel() const { return _zoomLevel; }
		void SetZoomLevel(float zoomLevel);

	private:
		float _zoomLevel;

	};

	class PerspectiveCamera : public Camera
	{
	public:
		PerspectiveCamera(float fov			= 45.0f,
						  float aspectRatio		= 16.0f / 9.0f,
						  float nearClip			= 0.1f,
						  float farClip			= 100.0f,
						  glm::vec3 position	= glm::vec3(),
						  glm::quat rotation	= glm::quat())
			: Camera(glm::perspective(glm::radians(fov), aspectRatio, nearClip, farClip), glm::mat4(1.0f), aspectRatio, position, rotation),
			  _fov(fov), _nearClip(nearClip), _farClip(farClip) {}

		void SetPerspectiveProjection(float fov, float aspectRatio, float nearClip, float farClip);

		float GetFOV() const { return _fov; }
		void SetFOV(float fov);

		void SetAspectRatio(float aspectRatio);

		float GetNearClip() const { return _nearClip; }
		void SetNearClip(float nearClip);

		float GetFarClip() const { return _farClip; }
		void SetFarClip(float farClip);

	private:
		float _fov;
		float _nearClip;
		float _farClip;
	};
}