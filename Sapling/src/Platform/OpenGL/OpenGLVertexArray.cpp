#include "sappch.h"
#include "OpenGLVertexArray.h"

#include <glad/gl.h>

namespace Sapling
{
	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
			case ShaderDataType::Float:		return GL_FLOAT;
			case ShaderDataType::Float2:	return GL_FLOAT;
			case ShaderDataType::Float3:	return GL_FLOAT;
			case ShaderDataType::Float4:	return GL_FLOAT;
			case ShaderDataType::Mat3:		return GL_FLOAT;
			case ShaderDataType::Mat4:		return GL_FLOAT;
			case ShaderDataType::Int:		return GL_INT;
			case ShaderDataType::Int2:		return GL_INT;
			case ShaderDataType::Int3:		return GL_INT;
			case ShaderDataType::Int4:		return GL_INT;
			case ShaderDataType::Bool:		return GL_BOOL;
		}

		throw std::runtime_error("Unknown ShaderDataType!");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &_rendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &_rendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(_rendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
	{
		if (vertexBuffer->GetLayout().GetElements().empty())
		{
			throw std::runtime_error("Vertex Buffer has no layout!");
		}

		glBindVertexArray(_rendererID);
		vertexBuffer->Bind();

		const BufferLayout& layout = vertexBuffer->GetLayout();
		for (const BufferElement& element : layout)
		{
			glEnableVertexAttribArray(_vertexBufferIndex);
			glVertexAttribPointer(_vertexBufferIndex,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);

			_vertexBufferIndex++;
		}

		_vertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(_rendererID);
		indexBuffer->Bind();

		_indexBuffer = indexBuffer;
	}
}
