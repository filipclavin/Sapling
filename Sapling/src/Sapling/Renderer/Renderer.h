#pragma once

#include "RendererAPI.h"
#include "Shader.h"

namespace Sapling
{
	class Camera;

	class Renderer
	{
	public:
		static void BeginScene(glm::mat4 viewProjectionMatrix);
		static void EndScene();

		static void Submit(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader> shader);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* _sceneData;
	};
}