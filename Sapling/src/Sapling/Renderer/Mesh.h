#pragma once
#include <Sapling/Renderer/VertexArray.h>

namespace Sapling
{
	class Mesh
	{
	public:
		Mesh(float* vertices, size_t vSize, unsigned int* indices, unsigned int iCount, BufferLayout bufferLayout)
			: _vertexArray(VertexArray::Create()),
			  _vertexBuffer(VertexBuffer::Create(vertices, vSize)),
			  _indexBuffer(IndexBuffer::Create(indices, iCount))
		{
			_vertexBuffer->SetLayout(bufferLayout);
			_vertexArray->AddVertexBuffer(_vertexBuffer);
			_vertexArray->SetIndexBuffer(_indexBuffer);
		}

		Mesh() = default;

		const std::shared_ptr<VertexArray>& GetVertexArray() const { return _vertexArray; }
		const std::shared_ptr<VertexBuffer>& GetVertexBuffer() const { return _vertexBuffer; }
		const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const { return _indexBuffer; }

	private:
		std::shared_ptr<VertexArray> _vertexArray;
		std::shared_ptr<VertexBuffer> _vertexBuffer;
		std::shared_ptr<IndexBuffer> _indexBuffer;
	};
}