#pragma once

#include<ForgeCraft/Core.h>
#include <ForgeCraft/Renderer/Buffer.h>

namespace ForgeCraft {

  class FORGECRAFT_API OpenGLVertexBuffer : public VertexBuffer<OpenGLVertexBuffer> {
  public:
    OpenGLVertexBuffer(GLfloat* data, GLuint size);
    ~OpenGLVertexBuffer();

    void Bind() ;
    void Unbind();

    void SetLayout(const BufferLayout& layout) {
            m_layout = layout;
    }
    const BufferLayout& GetLayout() const {
            return m_layout;
    }

  private:
    GLuint m_vbo;
    BufferLayout m_layout;
  };

  class FORGECRAFT_API OpenGLIndexBuffer : public IndexBuffer<OpenGLIndexBuffer> {
  public:
    OpenGLIndexBuffer(GLuint* data, GLuint size);
    ~OpenGLIndexBuffer();

    void Bind() ;
    void Unbind() ;
    uint32_t GetCount() const;

  private:
    GLuint m_count;
    GLuint m_ebo;
  };

}
