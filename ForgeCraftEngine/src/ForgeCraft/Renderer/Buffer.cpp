#include "fcpch.h"
#include "Buffer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"



namespace ForgeCraft {

  template<>
  OpenGLVertexBuffer* VertexBuffer<OpenGLVertexBuffer>::Create(GLfloat* data, GLuint size) {
    switch (RendererAPI<OpenGLVertexBuffer>::GetAPI()) {
    case RendererAPI<OpenGLVertexBuffer>::API::None:
      FC_CORE_WARN( "RendererAPI::None is not supported");
      return nullptr;
    case RendererAPI<OpenGLVertexBuffer>::API::OpenGL:
      return new OpenGLVertexBuffer(data, size);
    }
    FC_CORE_WARN("Unknown RendererAPI!");
    return nullptr;
  }

  template<>
  OpenGLIndexBuffer* IndexBuffer<OpenGLIndexBuffer>::Create(GLuint* data, GLuint size) {
    switch (RendererAPI<OpenGLIndexBuffer>::GetAPI()) {
    case RendererAPI<OpenGLIndexBuffer>::API::None:
      FC_CORE_WARN( "RendererAPI::None is not supported");
      return nullptr;
    case RendererAPI<OpenGLIndexBuffer>::API::OpenGL:
      return new OpenGLIndexBuffer(data, size);
    }
    FC_CORE_WARN("Unknown RendererAPI!");
    return nullptr;
  }

}
