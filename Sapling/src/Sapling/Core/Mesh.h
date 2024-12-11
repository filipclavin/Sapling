#pragma once

#include "Sapling/Core/Base.h"

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

namespace Sapling
{
	struct Vertex
	{
		Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 texCoords)
			: Position(position), Normal(normal), TexCoords(texCoords) {}

		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 TexCoords;
	};

	class Mesh
	{
	public:
		Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
			: _vertices(vertices), _indices(indices) {}
		// TODO: Add a constructor that takes in a file path to a model

		static Mesh Cube();

		void Draw();
		
	private:
		std::vector<Vertex> _vertices;
		std::vector<unsigned int> _indices;

	};
}