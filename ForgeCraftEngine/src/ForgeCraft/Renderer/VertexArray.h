#pragma once

#include <ForgeCraft/Renderer/RendererAPI.h>
#include<ForgeCraft/Core.h>

namespace ForgeCraft {

  class OpenGLVertexArray;
  class OpenGLVertexBuffer;
  class OpenGLIndexBuffer;

}


namespace ForgeCraft {

  



  template<typename Derived>
  class VertexArray {
  public:
    virtual ~VertexArray() = default;

    void Bind() {
      static_cast<Derived*>(this)->Bind();
    }

    void Unbind() {
      static_cast<Derived*>(this)->Unbind();
    }


    void AddVertexBuffer(auto* vertexBuffer) {
      static_cast<Derived*>(this)->AddVertexBuffer(vertexBuffer);
    }

    void SetIndexBuffer(auto* indexBuffer) {
      static_cast<Derived*>(this)->SetIndexBuffer(indexBuffer);
    }

    
    const std::vector<OpenGLVertexBuffer*> & GetVertexBuffer() const {
      return static_cast<const Derived*>(this)->GetVertexBuffer();
    }


    const OpenGLIndexBuffer * GetIndexBuffer() const {
      return static_cast<const Derived*>(this)->GetIndexBuffer();
    }



    static OpenGLVertexArray * Create();
  };




}  // namespace ForgeCraft
