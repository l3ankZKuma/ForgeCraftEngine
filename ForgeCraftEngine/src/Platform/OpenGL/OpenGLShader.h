#pragma once

#include <ForgeCraft/Renderer/Shader.h>

namespace ForgeCraft {

  class OpenGLShader : public Shader<OpenGLShader> {
  public:
    OpenGLShader(const char* vertexSrc, const char* fragmentSrc) noexcept;
    ~OpenGLShader() noexcept;

    void Bind() const noexcept;
    void UnBind() const noexcept;

  private:
    GLuint CompileShader(GLenum type, const char* source) noexcept;
    GLuint CreateShader(const char* vertexSrc, const char* fragmentSrc) noexcept;
  };

} // namespace ForgeCraft
