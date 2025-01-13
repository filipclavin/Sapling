#include "sappch.h"
#include "Camera.h"

#include "RendererAPI.h"

namespace Sapling
{
	// ----------------- Camera -----------------

	Camera::Camera(const glm::mat4& projectionMatrix,
				   const glm::mat4& viewMatrix,
				   float aspectRatio,
				   float nearClip,
				   float farClip,
				   const glm::vec3& position,
				   const glm::quat& rotation)
		: _projectionMatrix(projectionMatrix), _viewMatrix(viewMatrix), _aspectRatio(aspectRatio), _nearClip(nearClip), _farClip(farClip), _viewProjectionMatrix(projectionMatrix * viewMatrix)
	{
		SetPosition(position);
		SetRotation(rotation);
	}

	void Camera::SetProjectionMatrix(const glm::mat4& projectionMatrix)
	{
		_projectionMatrix = projectionMatrix;
		UpdateViewProjectionMatrix();
	}

	void Camera::SetViewMatrix(const glm::mat4& viewMatrix)
	{
		_viewMatrix = viewMatrix;
		UpdateViewProjectionMatrix();
	}

	void Camera::SetPosition(const glm::vec3& position)
	{
		_position = position;
		UpdateViewMatrix();
	}

	void Camera::SetRotation(const glm::quat& rotation)
	{
		_rotation = rotation;
		UpdateViewMatrix();
	}

	void Sapling::Camera::UpdateViewMatrix(bool skipViewProjectionMatrix)
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), _position) * glm::mat4_cast(_rotation);
		_viewMatrix = glm::inverse(transform);

		if (skipViewProjectionMatrix) return;

		UpdateViewProjectionMatrix();
	}

	void Camera::UpdateViewProjectionMatrix()
	{
		switch (RendererAPI::GetAPI())
		{
			case RendererAPI::API::None:
				throw std::runtime_error("RendererAPI::None is currently not supported");
				break;
			case RendererAPI::API::OpenGL:
				_viewProjectionMatrix = _projectionMatrix * _viewMatrix;
				break;
		}
	}

	// ----------------- OrthographicCamera -----------------

	void Sapling::OrthographicCamera::UpdateProjectionMatrix()
	{
		SetProjectionMatrix(glm::ortho(-_aspectRatio * _zoomLevel, _aspectRatio * _zoomLevel, -_zoomLevel, _zoomLevel, _nearClip, _farClip));
	}

	void OrthographicCamera::CopySharedProperties(const Camera& other)
	{
		_position = other.GetPosition();
		_rotation = other.GetRotation();
		_nearClip = other.GetNearClip();
		_farClip = other.GetFarClip();
		_aspectRatio = other.GetAspectRatio();
		UpdateViewMatrix(true);
		UpdateProjectionMatrix();
	}

	void OrthographicCamera::SetNearClip(float nearClip)
	{
		_nearClip = nearClip;
		UpdateProjectionMatrix();
	}

	void OrthographicCamera::SetFarClip(float farClip)
	{
		_farClip = farClip;
		UpdateProjectionMatrix();
	}

	void OrthographicCamera::SetAspectRatio(float aspectRatio)
	{
		_aspectRatio = aspectRatio;
		UpdateProjectionMatrix();
	}

	void OrthographicCamera::SetZoomLevel(float zoomLevel)
	{
		_zoomLevel = zoomLevel;
		UpdateProjectionMatrix();
	}

	// ----------------- PerspectiveCamera -----------------

	void Sapling::PerspectiveCamera::UpdateProjectionMatrix()
	{
		SetProjectionMatrix(glm::perspective(glm::radians(_fov), _aspectRatio, _nearClip, _farClip));
	}

	void PerspectiveCamera::CopySharedProperties(const Camera& other)
	{
		_position = other.GetPosition();
		_rotation = other.GetRotation();
		_nearClip = other.GetNearClip();
		_farClip = other.GetFarClip();
		_aspectRatio = other.GetAspectRatio();
		UpdateViewMatrix(true);
		UpdateProjectionMatrix();
	}

	void PerspectiveCamera::SetFOV(float fov)
	{
		_fov = fov;
		UpdateProjectionMatrix();
	}

	void PerspectiveCamera::SetNearClip(float nearClip)
	{
		_nearClip = nearClip;
		UpdateProjectionMatrix();
	}

	void PerspectiveCamera::SetFarClip(float farClip)
	{
		_farClip = farClip;
		UpdateProjectionMatrix();
	}

	void PerspectiveCamera::SetAspectRatio(float aspectRatio)
	{
		_aspectRatio = aspectRatio;
		UpdateProjectionMatrix();
	}
}
