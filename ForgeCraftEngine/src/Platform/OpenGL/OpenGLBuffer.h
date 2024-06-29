#pragma once

#include <ForgeCraft/Renderer/Buffer.h>

namespace ForgeCraft {

  class OpenGLVertexBuffer : public VertexBuffer<OpenGLVertexBuffer> {
  public:
    OpenGLVertexBuffer(GLfloat* data, GLuint size);
    ~OpenGLVertexBuffer();

    void Bind() ;
    void Unbind();

  private:
    GLuint m_vbo;
  };

  class OpenGLIndexBuffer : public IndexBuffer<OpenGLIndexBuffer> {
  public:
    OpenGLIndexBuffer(GLuint* data, GLuint size);
    ~OpenGLIndexBuffer();

    void Bind() ;
    void Unbind() ;

  private:
    GLuint m_ebo;
  };

}