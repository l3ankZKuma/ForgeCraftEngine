#pragma once

#include <ForgeCraft/Renderer/RendererAPI.h>
#include <ForgeCraft/Renderer/Buffer.h>
#include<Platform/OpenGL/OpenGLBuffer.h>



namespace ForgeCraft {


  using VBO = VertexBuffer<OpenGLVertexBuffer>;
  using EBO = IndexBuffer<OpenGLIndexBuffer>;


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

    
    const std::vector<VBO*> & GetVertexBuffer() const {
      return static_cast<const Derived*>(this)->GetVertexBuffer();
    }


    const EBO * GetIndexBuffer() const {
      return static_cast<const Derived*>(this)->GetIndexBuffer();
    }



    static VertexArray<Derived>* Create();
  };




}  // namespace ForgeCraft
