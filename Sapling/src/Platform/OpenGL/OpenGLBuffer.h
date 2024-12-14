#pragma once

#include "Sapling/Renderer/Buffer.h"

namespace Sapling
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, size_t size);
		~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual const BufferLayout& GetLayout() const override { return _layout; }
		virtual void SetLayout(const BufferLayout& layout) override { _layout = layout; }

	private:
		unsigned int _rendererID;
		BufferLayout _layout;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(unsigned int* indices, size_t count);
		~OpenGLIndexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual unsigned int GetCount() const override { return _count; }

	private:
		unsigned int _rendererID;
		unsigned int _count;
	};
}