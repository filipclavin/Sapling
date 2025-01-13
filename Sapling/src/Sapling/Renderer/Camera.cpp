#include "sappch.h"
#include "Camera.h"

#include "RendererAPI.h"

namespace Sapling
{
	Camera::Camera(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix, float aspectRatio, glm::vec3 position, glm::quat rotation)
		: _projectionMatrix(projectionMatrix), _viewMatrix(viewMatrix), _aspectRatio(aspectRatio), _viewProjectionMatrix(projectionMatrix * viewMatrix)
	{
		SetPosition(position);
		SetRotation(rotation);
	}

	void Camera::SetProjectionMatrix(const glm::mat4& projectionMatrix)
	{
		_projectionMatrix = projectionMatrix;
		_viewProjectionMatrix = _projectionMatrix * _viewMatrix;
	}

	void Camera::SetViewMatrix(const glm::mat4& viewMatrix)
	{
		_viewMatrix = viewMatrix;
		_viewProjectionMatrix = _projectionMatrix * _viewMatrix;
	}

	void Camera::SetPosition(const glm::vec3& position)
	{
		_position = position;
		RecalculateViewMatrix();
	}

	void Camera::SetRotation(const glm::quat& rotation)
	{
		_rotation = rotation;
		RecalculateViewMatrix();
	}

	void Camera::RecalculateViewMatrix()
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), _position) *
			glm::mat4_cast(_rotation);
		_viewMatrix = glm::inverse(transform);
		_viewProjectionMatrix = _projectionMatrix * _viewMatrix;
	}

	void OrthographicCamera::SetOrthoProjection(float aspectRatio, float zoomLevel)
	{
		SetProjectionMatrix(glm::ortho(-aspectRatio * zoomLevel, aspectRatio* zoomLevel, -zoomLevel, zoomLevel));
	}

	void OrthographicCamera::SetAspectRatio(float aspectRatio)
	{
		SetProjectionMatrix(glm::ortho(-aspectRatio * _zoomLevel, aspectRatio * _zoomLevel, -_zoomLevel, _zoomLevel));
	}

	void OrthographicCamera::SetZoomLevel(float zoomLevel)
	{
		_zoomLevel = zoomLevel;
		SetProjectionMatrix(glm::ortho(-_aspectRatio * zoomLevel, _aspectRatio * zoomLevel, -zoomLevel, zoomLevel));
	}

	void PerspectiveCamera::SetPerspectiveProjection(float fov, float aspectRatio, float nearClip, float farClip)
	{
		_fov = fov;
		_aspectRatio = aspectRatio;
		_nearClip = nearClip;
		_farClip = farClip;
		SetProjectionMatrix(glm::perspective(glm::radians(fov), aspectRatio, nearClip, farClip));
	}

	void PerspectiveCamera::SetFOV(float fov)
	{
		SetProjectionMatrix(glm::perspective(glm::radians(fov), _aspectRatio, _nearClip, _farClip));
	}

	void PerspectiveCamera::SetAspectRatio(float aspectRatio)
	{
		SetProjectionMatrix(glm::perspective(glm::radians(_fov), aspectRatio, _nearClip, _farClip));
	}

	void PerspectiveCamera::SetNearClip(float nearClip)
	{
		SetProjectionMatrix(glm::perspective(glm::radians(_fov), _aspectRatio, nearClip, _farClip));
	}

	void PerspectiveCamera::SetFarClip(float farClip)
	{
		SetProjectionMatrix(glm::perspective(glm::radians(_fov), _aspectRatio, _nearClip, farClip));
	}
}
