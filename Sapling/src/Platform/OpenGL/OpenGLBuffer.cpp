#include "sappch.h"
#include "OpenGLBuffer.h"

#include <glad/gl.h>

namespace Sapling
{
	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, size_t size)
		: _layout({}), _rendererID(0)
	{
		glCreateBuffers(1, &_rendererID);
		glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &_rendererID);
	}
	
	void OpenGLVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
	}
	
	void OpenGLVertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	
	OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int* indices, size_t count)
		: _count(count)
	{
		glCreateBuffers(1, &_rendererID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW);
	}
	
	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &_rendererID);
	}
	
	void OpenGLIndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID);
	}
	
	void OpenGLIndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}