#include "sappch.h"
#include "VertexArray.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Sapling
{
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
			throw std::runtime_error("RendererAPI::None is not supported!");
		case RendererAPI::OpenGL:
			return new OpenGLVertexArray();
		}
		throw std::runtime_error("Unknown RendererAPI!");
	}
}