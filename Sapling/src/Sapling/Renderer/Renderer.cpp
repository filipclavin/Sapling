#include "sappch.h"
#include "Renderer.h"

#include "RenderCommand.h"
#include "Camera.h"
#include <glad/gl.h>

namespace Sapling
{
	Renderer::SceneData* Renderer::_sceneData = new SceneData();

    void Sapling::Renderer::BeginScene(glm::mat4 viewProjectionMatrix)
    {
		_sceneData->ViewProjectionMatrix = viewProjectionMatrix;
    }

    void Renderer::EndScene()
    {
    }

	void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader> shader)
    {
		shader->Bind();
		shader->SetMat4("u_ViewProjection", _sceneData->ViewProjectionMatrix);

		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
    }
}