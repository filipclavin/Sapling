#include "sappch.h"
#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Sapling
{
	std::shared_ptr<Shader> Sapling::Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:
				throw std::runtime_error("RendererAPI::None is not supported!");

			case RendererAPI::API::OpenGL:
				return std::make_shared<OpenGLShader>(vertexSrc, fragmentSrc);
		}

		throw std::runtime_error("Unknown RendererAPI!");
	}
}