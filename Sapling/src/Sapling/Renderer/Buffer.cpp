#include "sappch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Sapling
{
	std::shared_ptr<VertexBuffer> Sapling::VertexBuffer::Create(float* vertices, size_t size)
	{
		switch (RendererAPI::GetAPI())
		{
			case RendererAPI::API::None:
				throw std::runtime_error("RendererAPI::None is not supported!");

			case RendererAPI::API::OpenGL:
				return std::make_shared<OpenGLVertexBuffer>(vertices, size);
		}

		throw std::runtime_error("Unknown RendererAPI!");
	}

	std::shared_ptr<IndexBuffer> Sapling::IndexBuffer::Create(unsigned int* indices, size_t count)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:
				throw std::runtime_error("RendererAPI::None is not supported!");
			
			case RendererAPI::API::OpenGL:
				return std::make_shared<OpenGLIndexBuffer>(indices, count);
		}

		throw std::runtime_error("Unknown RendererAPI!");
	}
}