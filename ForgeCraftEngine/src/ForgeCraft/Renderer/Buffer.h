#pragma once

#include <glad/glad.h>  // Use glad for OpenGL function loading
#include "ForgeCraft/Renderer/RendererAPI.h"
#include <ForgeCraft/Log.h>

namespace ForgeCraft {

  template<typename Derived>
  class VertexBuffer {
  public:
    ~VertexBuffer() = default;

    void Bind()  {
      static_cast<Derived*>(this)->Bind();
    }
    void Unbind() {
      static_cast<Derived*>(this)->Unbind();
    }

    static VertexBuffer<Derived>* Create(GLfloat* data, GLuint size);
  };

  template<typename Derived>
  class IndexBuffer {
  public:
    ~IndexBuffer() = default;

    void Bind() {
      static_cast<Derived*>(this)->Bind();
    }
    void Unbind()  {
      static_cast<Derived*>(this)->Unbind();
    }

    static IndexBuffer<Derived>* Create(GLuint* data, GLuint size);
  };

}
