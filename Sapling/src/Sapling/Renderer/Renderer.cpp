#include "sappch.h"
#include "Renderer.h"

#include "RenderCommand.h"

namespace Sapling
{
    void Renderer::BeginScene()
    {

    }

    void Renderer::EndScene()
    {
    }

    void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray)
    {
		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
    }
}