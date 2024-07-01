#pragma once

#include <ForgeCraft/Renderer/Shader.h>
#include <glm/gtc/type_ptr.hpp> // For glm::value_ptr

namespace ForgeCraft {

  class OpenGLShader : public Shader<OpenGLShader> {
  public:
    OpenGLShader(const char* vertexSrc, const char* fragmentSrc) noexcept;
    ~OpenGLShader() noexcept;

    void Bind() const noexcept;
    void UnBind() const noexcept;

    inline void SetIntImpl(const char* name, int value) noexcept {
      glUniform1i(glGetUniformLocation(m_rendererID, name), value);
    }

    inline void SetFloatImpl(const char* name, float value) noexcept {
      glUniform1f(glGetUniformLocation(m_rendererID, name), value);
    }

    inline void SetFloat2Impl(const char* name, const glm::vec2& value) noexcept {
      glUniform2f(glGetUniformLocation(m_rendererID, name), value.x, value.y);
    }

    inline void SetFloat3Impl(const char* name, const glm::vec3& value) noexcept {
      glUniform3f(glGetUniformLocation(m_rendererID, name), value.x, value.y, value.z);
    }

    inline void SetFloat4Impl(const char* name, const glm::vec4& value) noexcept {
      glUniform4f(glGetUniformLocation(m_rendererID, name), value.x, value.y, value.z, value.w);
    }

    inline void SetMat4Impl(const char* name, const glm::mat4& value) noexcept {
      glUniformMatrix4fv(glGetUniformLocation(m_rendererID, name), 1, GL_FALSE, glm::value_ptr(value));
    }

  private:
    GLuint CompileShader(GLenum type, const char* source) noexcept;
    GLuint CreateShader(const char* vertexSrc, const char* fragmentSrc) noexcept;
    GLuint m_rendererID;
  };

} // namespace ForgeCraft
