#pragma once

#include "Sapling/Renderer/VertexArray.h"

namespace Sapling
{
	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override;
		virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const override { return _vertexBuffers; }
		virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const override { return _indexBuffer; }

	private:
		uint32_t _rendererID;
		std::vector<std::shared_ptr<VertexBuffer>> _vertexBuffers;
		std::shared_ptr<IndexBuffer> _indexBuffer;

		uint32_t _vertexBufferIndex = 0;
	};

}