#include "sappch.h"
#include "Mesh.h"

namespace Sapling
{
    Mesh Sapling::Mesh::Cube()
    {
		std::vector<Vertex> structTest = {
			Vertex({-0.5f, -0.5f,  0.5f}, { 0.0f,  0.0f,  1.0f}, { 0.0f,  0.0f}),
			Vertex({ 0.5f, -0.5f,  0.5f}, { 0.0f,  0.0f,  1.0f}, { 1.0f,  0.0f}),
		};
		std::vector<float> expectedData = {
			-0.5f, -0.5f,  0.5f, 0.0f,  0.0f,  1.0f, 0.0f,  0.0f,
			0.5f, -0.5f,  0.5f, 0.0f,  0.0f,  1.0f, 1.0f,  0.0f
		};

        std::vector<Vertex> vertices = {
			// Front face
			Vertex({-0.5f, -0.5f,  0.5f}, { 0.0f,  0.0f,  1.0f}, { 0.0f,  0.0f}),
			Vertex({ 0.5f, -0.5f,  0.5f}, { 0.0f,  0.0f,  1.0f}, { 1.0f,  0.0f}),
			Vertex({ 0.5f,  0.5f,  0.5f}, { 0.0f,  0.0f,  1.0f}, { 1.0f,  1.0f}),
			Vertex({-0.5f,  0.5f,  0.5f}, { 0.0f,  0.0f,  1.0f}, { 0.0f,  1.0f}),

			// Back face
			Vertex({-0.5f, -0.5f, -0.5f}, { 0.0f,  0.0f, -1.0f}, { 1.0f,  0.0f}),
			Vertex({ 0.5f, -0.5f, -0.5f}, { 0.0f,  0.0f, -1.0f}, { 0.0f,  0.0f}),
			Vertex({ 0.5f,  0.5f, -0.5f}, { 0.0f,  0.0f, -1.0f}, { 0.0f,  1.0f}),
			Vertex({-0.5f,  0.5f, -0.5f}, { 0.0f,  0.0f, -1.0f}, { 1.0f,  1.0f}),

			// Left face
			Vertex({-0.5f, -0.5f, -0.5f}, {-1.0f,  0.0f,  0.0f}, { 0.0f,  0.0f}),
			Vertex({-0.5f, -0.5f,  0.5f}, {-1.0f,  0.0f,  0.0f}, { 1.0f,  0.0f}),
			Vertex({-0.5f,  0.5f,  0.5f}, {-1.0f,  0.0f,  0.0f}, { 1.0f,  1.0f}),
			Vertex({-0.5f,  0.5f, -0.5f}, {-1.0f,  0.0f,  0.0f}, { 0.0f,  1.0f}),

			// Right face
			Vertex({ 0.5f, -0.5f, -0.5f}, { 1.0f,  0.0f,  0.0f}, { 1.0f,  0.0f}),
			Vertex({ 0.5f, -0.5f,  0.5f}, { 1.0f,  0.0f,  0.0f}, { 0.0f,  0.0f}),
			Vertex({ 0.5f,  0.5f,  0.5f}, { 1.0f,  0.0f,  0.0f}, { 0.0f,  1.0f}),
			Vertex({ 0.5f,  0.5f, -0.5f}, { 1.0f,  0.0f,  0.0f}, { 1.0f,  1.0f}),

			// Top face
			Vertex({-0.5f,  0.5f, -0.5f}, { 0.0f,  1.0f,  0.0f}, { 0.0f,  1.0f}),
			Vertex({ 0.5f,  0.5f, -0.5f}, { 0.0f,  1.0f,  0.0f}, { 1.0f,  1.0f}),
			Vertex({ 0.5f,  0.5f,  0.5f}, { 0.0f,  1.0f,  0.0f}, { 1.0f,  0.0f}),
			Vertex({-0.5f,  0.5f,  0.5f}, { 0.0f,  1.0f,  0.0f}, { 0.0f,  0.0f}),

			// Bottom face
			Vertex({-0.5f, -0.5f, -0.5f}, { 0.0f, -1.0f,  0.0f}, { 0.0f,  0.0f}),
			Vertex({ 0.5f, -0.5f, -0.5f}, { 0.0f, -1.0f,  0.0f}, { 1.0f,  0.0f}),
			Vertex({ 0.5f, -0.5f,  0.5f}, { 0.0f, -1.0f,  0.0f}, { 1.0f,  1.0f}),
			Vertex({-0.5f, -0.5f,  0.5f}, { 0.0f, -1.0f,  0.0f}, { 0.0f,  1.0f})
        };

		std::vector<unsigned int> indices = {
			// Front face
			0, 1, 2,
			2, 3, 0,

			// Back face
			4, 5, 6,
			6, 7, 4,

			// Left face
			8, 9, 10,
			10, 11, 8,

			// Right face
			12, 13, 14,
			14, 15, 12,

			// Top face
			16, 17, 18,
			18, 19, 16,

			// Bottom face
			20, 21, 22,
			22, 23, 20
		};

		return Mesh(vertices, indices);
    }

    void Mesh::Draw()
    {
    }
}
