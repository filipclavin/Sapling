#pragma once

#include "Sapling/Renderer/GraphicsContext.h"

struct GLFWmonitor;
struct GLFWwindow;

namespace Sapling
{
    class OpenGLContext : public RenderingContext
    {
    public:
        OpenGLContext(int width, int height,
                      const char* title,
                      GLFWmonitor* monitor,
                      GLFWwindow* share,
                      GLFWwindow*& outWindow);

		virtual void Init() override;
        virtual void SwapBuffers() override;
		virtual void SetVSync(bool enabled) override;

    private:
        GLFWwindow* _nativeWindow;
    };
}