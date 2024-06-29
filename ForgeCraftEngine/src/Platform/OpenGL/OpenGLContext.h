#pragma once


#include "ForgeCraft/Core.h"
#include "ForgeCraft/Renderer/GraphicsContext.h"


namespace ForgeCraft {

  class FORGECRAFT_API OpenGLContext : public GraphicsContext<OpenGLContext>
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
