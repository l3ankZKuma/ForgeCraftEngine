#include "fcpch.h"
#include "OpenGLContext.h"



namespace ForgeCraft {

  OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
    : m_windowHandle(windowHandle) {}

  void OpenGLContext::InitImpl() {

    glfwMakeContextCurrent(m_windowHandle);
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
  }

  void OpenGLContext::SwapBuffersImpl() {

    glfwSwapBuffers(m_windowHandle);
  }
}