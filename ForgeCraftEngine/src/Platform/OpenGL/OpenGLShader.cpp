#include "fcpch.h"
#include "OpenGLShader.h"
#include "ForgeCraft/Log.h"

namespace ForgeCraft {

  OpenGLShader::OpenGLShader(const char* vertexSrc, const char* fragmentSrc) noexcept {
    m_rendererID = CreateShader(vertexSrc, fragmentSrc);
  }

  OpenGLShader::~OpenGLShader() noexcept {
    glDeleteProgram(m_rendererID);
  }

  void OpenGLShader::Bind() const noexcept {
    glUseProgram(m_rendererID);
  }

  void OpenGLShader::UnBind() const noexcept {
    glUseProgram(0);
  }

  GLuint OpenGLShader::CompileShader(GLenum type, const char* source) noexcept {
    GLuint id = glCreateShader(type);
    glShaderSource(id, 1, &source, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
      int length;
      glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
      char* message = new char[length];
      glGetShaderInfoLog(id, length, &length, message);
      FC_CORE_ERROR("Failed to compile {} shader!", (type == GL_VERTEX_SHADER ? "vertex" : "fragment"));
      FC_CORE_ERROR("Error: {}", message);
      delete[] message;
      glDeleteShader(id);
      return 0;
    }

    FC_CORE_INFO("{} shader compiled successfully.", (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment"));
    return id;
  }

  GLuint OpenGLShader::CreateShader(const char* vertexSrc, const char* fragmentSrc) noexcept {
    GLuint program = glCreateProgram();
    GLuint vs = CompileShader(GL_VERTEX_SHADER, vertexSrc);
    GLuint fs = CompileShader(GL_FRAGMENT_SHADER, fragmentSrc);

    if (vs == 0 || fs == 0) {
      FC_CORE_ERROR("Shader creation failed.");
      return 0;
    }

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    int isLinked;
    glGetProgramiv(program, GL_LINK_STATUS, &isLinked);
    if (isLinked == GL_FALSE) {
      int length;
      glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
      char* message = new char[length];
      glGetProgramInfoLog(program, length, &length, message);
      FC_CORE_ERROR("Failed to link shader program.");
      FC_CORE_ERROR("Error: {}", message);
      delete[] message;
      glDeleteProgram(program);
      return 0;
    }

    glDeleteShader(vs);
    glDeleteShader(fs);

    FC_CORE_INFO("Shader program created successfully.");
    return program;
  }

} // namespace ForgeCraft
