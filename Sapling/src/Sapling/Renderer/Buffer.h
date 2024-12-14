#pragma once

namespace Sapling
{
	enum class ShaderDataType
	{
		None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
	};

	static unsigned int ShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
			case ShaderDataType::Float:		return 4;
			case ShaderDataType::Float2:	return 4 * 2;
			case ShaderDataType::Float3:	return 4 * 3;
			case ShaderDataType::Float4:	return 4 * 4;
			case ShaderDataType::Mat3:		return 4 * 3 * 3;
			case ShaderDataType::Mat4:		return 4 * 4 * 4;
			case ShaderDataType::Int:		return 4;
			case ShaderDataType::Int2:		return 4 * 2;
			case ShaderDataType::Int3:		return 4 * 3;
			case ShaderDataType::Int4:		return 4 * 4;
			case ShaderDataType::Bool:		return 1;
		}

		throw std::runtime_error("Unknown ShaderDataType!");
		return 0;
	}

	struct BufferElement
	{
		ShaderDataType Type;
		std::string Name;
		unsigned int Size;
		unsigned int Offset;
		bool Normalized;

		BufferElement() {}
		BufferElement(ShaderDataType type, std::string name, bool normalized = false)
			: Type(type), Name(name), Size(ShaderDataTypeSize(type)), Offset(0), Normalized(normalized) {}

		unsigned int GetComponentCount() const
		{
			switch (Type)
			{
				case ShaderDataType::Float:		return 1;
				case ShaderDataType::Float2:	return 2;
				case ShaderDataType::Float3:	return 3;
				case ShaderDataType::Float4:	return 4;
				case ShaderDataType::Mat3:		return 3 * 3;
				case ShaderDataType::Mat4:		return 4 * 4;
				case ShaderDataType::Int:		return 1;
				case ShaderDataType::Int2:		return 2;
				case ShaderDataType::Int3:		return 3;
				case ShaderDataType::Int4:		return 4;
				case ShaderDataType::Bool:		return 1;
			}

			throw std::runtime_error("Unknown ShaderDataType!");
			return 0;
		}
	};

    class BufferLayout
    {
    public:
		BufferLayout() {}
        BufferLayout(const std::initializer_list<BufferElement>& elements)
            : _elements(elements)
        {
            CalculateStrideAndOffset();
        }

        unsigned int GetStride() const { return _stride; }
        inline const std::vector<BufferElement>& GetElements() const { return _elements; }

		std::vector<BufferElement>::iterator begin() { return _elements.begin(); }
		std::vector<BufferElement>::iterator end() { return _elements.end(); }
		std::vector<BufferElement>::const_iterator begin() const { return _elements.begin(); }
        std::vector<BufferElement>::const_iterator end() const { return _elements.end(); }

    private:
        void CalculateStrideAndOffset()
        {
            unsigned int offset = 0;
            _stride = 0;
            for (BufferElement& element : _elements)
            {
                element.Offset = offset;
                offset += element.Size;
                _stride += element.Size;
            }
        }

        std::vector<BufferElement> _elements;
        unsigned int _stride = 0;
    };

	class VertexBuffer
	{
	public:
		static VertexBuffer* Create(float* vertices, size_t size);

		~VertexBuffer() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual const BufferLayout& GetLayout() const = 0;
		virtual void SetLayout(const BufferLayout& layout) = 0;
	};

	class IndexBuffer
	{
	public:
		static IndexBuffer* Create(unsigned int* indices, size_t count);

		~IndexBuffer() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual unsigned int GetCount() const = 0;
	};

}