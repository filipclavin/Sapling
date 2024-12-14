#include "sappch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Sapling
{
	VertexBuffer* VertexBuffer::Create(float* vertices, size_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:
				throw std::runtime_error("RendererAPI::None is not supported!");

			case RendererAPI::OpenGL:
				return new OpenGLVertexBuffer(vertices, size);
		}

		throw std::runtime_error("Unknown RendererAPI!");
	}

	IndexBuffer* IndexBuffer::Create(unsigned int* indices, size_t count)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:
				throw std::runtime_error("RendererAPI::None is not supported!");
			
			case RendererAPI::OpenGL:
				return new OpenGLIndexBuffer(indices, count);
		}

		throw std::runtime_error("Unknown RendererAPI!");
	}
}