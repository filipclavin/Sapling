#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace Sapling
{
	class Camera
	{
	public:
		const glm::vec3& GetPosition() const { return _position; }
		void SetPosition(const glm::vec3& position);

		const glm::quat& GetRotation() const { return _rotation; }
		void SetRotation(const glm::quat& rotation);

		float GetNearClip() const { return _nearClip; }
		virtual void SetNearClip(float nearClip) = 0;

		float GetFarClip() const { return _farClip; }
		virtual void SetFarClip(float farClip) = 0;

		float GetAspectRatio() const { return _aspectRatio; }
		virtual void SetAspectRatio(float aspectRatio) = 0;

		virtual void CopySharedProperties(const Camera& other) = 0;

		const glm::mat4& GetProjectionMatrix() const { return _projectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return _viewMatrix; }
		const glm::mat4& GetViewProjectionMatrix() const { return _viewProjectionMatrix; }

	protected:
		Camera(const glm::mat4& projectionMatrix,
			   const glm::mat4& viewMatrix,
			   float aspectRatio,
			   float nearClip,
			   float farClip,
			   const glm::vec3& position,
			   const glm::quat& rotation);

		void SetProjectionMatrix(const glm::mat4& projectionMatrix);
		void SetViewMatrix(const glm::mat4& viewMatrix);

		void UpdateViewMatrix(bool skipViewProjectionMatrix = false);
		void UpdateViewProjectionMatrix();

		glm::vec3 _position;
		glm::quat _rotation;

		float _aspectRatio;

		glm::mat4 _projectionMatrix;
		glm::mat4 _viewMatrix;
		glm::mat4 _viewProjectionMatrix;
		
		float _nearClip;
		float _farClip;
	};

	class OrthographicCamera : public Camera
	{
	public:
		OrthographicCamera(float aspectRatio			= 16.0f / 9.0f,
						   float zoomLevel				= 1.0f,
						   float nearClip				= 0.1f,
						   float farClip				= 100.0f,
						   const glm::vec3& position	= { 0.0f, 0.0f, 5.0f },
						   const glm::quat& rotation	= { 1.0f, 0.0f, 0.0f, 0.0f })
			: Camera(glm::ortho(-aspectRatio * zoomLevel,
								 aspectRatio * zoomLevel,
								-zoomLevel,
								 zoomLevel,
								 nearClip,
								 farClip), glm::mat4(1.0f), aspectRatio, nearClip, farClip, position, rotation), _zoomLevel(zoomLevel) {}

		virtual void CopySharedProperties(const Camera& other) override;

		virtual void SetNearClip(float nearClip) override;

		virtual void SetFarClip(float farClip) override;

		virtual void SetAspectRatio(float aspectRatio) override;

		float GetZoomLevel() const { return _zoomLevel; }
		void SetZoomLevel(float zoomLevel);

	private:
		void UpdateProjectionMatrix();

		float _zoomLevel;

	};

	class PerspectiveCamera : public Camera
	{
	public:
		PerspectiveCamera(float fov					= 45.0f,
						  float aspectRatio			= 16.0f / 9.0f,
						  float nearClip			= 0.1f,
						  float farClip				= 100.0f,
						  const glm::vec3& position	= { 0.0f, 0.0f, 5.0f },
						  const glm::quat& rotation	= { 1.0f, 0.0f, 0.0f, 0.0f })
			: Camera(glm::perspective(glm::radians(fov),
									  aspectRatio,
									  nearClip,
									  farClip), glm::mat4(1.0f), aspectRatio, nearClip, farClip, position, rotation), _fov(fov) {}

		virtual void CopySharedProperties(const Camera& other) override;

		float GetFOV() const { return _fov; }
		void SetFOV(float fov);
		
		virtual void SetNearClip(float nearClip) override;

		virtual void SetFarClip(float farClip) override;

		virtual void SetAspectRatio(float aspectRatio) override;

	private:
		void UpdateProjectionMatrix();

		float _fov;

	};

	enum class CameraType
	{
		Orthographic = 0, Perspective = 1
	};
}