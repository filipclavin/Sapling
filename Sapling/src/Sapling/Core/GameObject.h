#pragma once

#include "Sapling/Core/Transform.h"
#include "Sapling/Renderer/Mesh.h"
#include "Sapling/Renderer/Shader.h"

namespace Sapling
{
	class GameObject
	{
	public:
		GameObject(const std::string& name,
				   const std::shared_ptr<Transform> transform,
				   const std::shared_ptr<Mesh> mesh,
				   const std::shared_ptr<Shader> shader)
			: Name(name), Transform(transform), Mesh(mesh), Shader(shader) {}

		GameObject(const std::string& name, const std::shared_ptr<Transform> transform, const std::shared_ptr<Mesh> mesh)
			: Name(name), Transform(transform), Mesh(mesh), Shader(nullptr) {}

		GameObject(const std::string& name, const std::shared_ptr<Transform> transform, const std::shared_ptr<Shader> shader)
			: Name(name), Transform(transform), Mesh(nullptr), Shader(shader) {}

		GameObject(const std::string& name, const std::shared_ptr<Mesh> mesh, const std::shared_ptr<Shader> shader)
			: Name(name), Transform(std::make_shared<Sapling::Transform>()), Mesh(mesh), Shader(shader) {}

		GameObject(const std::string& name, const std::shared_ptr<Transform> transform)
			: Name(name), Transform(transform), Mesh(nullptr), Shader(nullptr) {}

		GameObject(const std::string& name, const std::shared_ptr<Mesh> mesh)
			: Name(name), Transform(std::make_shared<Sapling::Transform>()), Mesh(mesh), Shader(nullptr) {}

		GameObject(const std::string& name, const std::shared_ptr<Shader> shader)
			: Name(name), Transform(std::make_shared<Sapling::Transform>()), Mesh(nullptr), Shader(shader) {}

		GameObject() = default;

		std::string Name = "Entity";
		std::shared_ptr<Transform> Transform;
		std::shared_ptr<Mesh> Mesh;
		std::shared_ptr<Shader> Shader;

		// TODO: Components
	};
}