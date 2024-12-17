#include "sappch.h"
#include "VertexArray.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Sapling
{
	std::shared_ptr<VertexArray> Sapling::VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			throw std::runtime_error("RendererAPI::None is not supported!");
		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLVertexArray>();
		}
		throw std::runtime_error("Unknown RendererAPI!");
	}
}