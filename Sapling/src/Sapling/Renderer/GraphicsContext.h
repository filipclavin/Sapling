#pragma once

namespace Sapling
{
	class RenderingContext
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
		virtual void SetVSync(bool enabled) = 0;
	};
}