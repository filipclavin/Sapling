#include "sappch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Sapling
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();
}

