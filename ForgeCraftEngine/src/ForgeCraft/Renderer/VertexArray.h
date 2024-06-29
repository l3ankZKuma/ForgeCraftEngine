#pragma once


#include <ForgeCraft/Renderer/RendererAPI.h>
#include <ForgeCraft/Renderer/Buffer.h>



namespace ForgeCraft {

  template<typename Derived>
  class  VertexArray {
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

    static VertexArray<Derived>* Create();
  };

}  // namespace ForgeCraft
