#include "sappch.h"
#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Sapling
{
	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:
				throw std::runtime_error("RendererAPI::None is not supported!");

			case RendererAPI::OpenGL:
				return new OpenGLShader(vertexSrc, fragmentSrc);
		}

		throw std::runtime_error("Unknown RendererAPI!");
	}
}