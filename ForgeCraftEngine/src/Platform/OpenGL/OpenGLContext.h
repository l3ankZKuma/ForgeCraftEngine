#pragma once

#include "ForgeCraft/Renderer/GraphicsContext.h"


namespace ForgeCraft {

  class OpenGLContext : public GraphicsContext<OpenGLContext>
  {
  public:
    OpenGLContext(GLFWwindow* windowHandle);
    ~OpenGLContext() = default;

    void InitImpl();

    void SwapBuffersImpl();

  private:
    GLFWwindow* m_windowHandle;
  };

}
