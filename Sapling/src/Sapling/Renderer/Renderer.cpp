#include "sappch.h"
#include "Renderer.h"

#include "RenderCommand.h"
#include "Camera.h"
#include <glad/gl.h>

namespace Sapling
{
	Renderer::SceneData* Renderer::_sceneData = new SceneData();

    void Sapling::Renderer::BeginScene(const glm::mat4& viewProjectionMatrix)
    {
		_sceneData->ViewProjectionMatrix = viewProjectionMatrix;
    }

    void Renderer::EndScene()
    {
    }

	void Sapling::Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader> shader, const glm::mat4& transform = glm::mat4(1.0f))
    {
		shader->Bind();
		shader->SetMat4("u_ViewProjection", _sceneData->ViewProjectionMatrix);
		shader->SetMat4("u_Transform", transform);

		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
    }
}