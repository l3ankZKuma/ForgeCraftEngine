#pragma once

#include<ForgeCraft/Core.h>
#include"ForgeCraft/Renderer/VertexArray.h"
#include<Platform/OpenGL/OpenGLBuffer.h>

namespace ForgeCraft {

  class FORGECRAFT_API OpenGLVertexArray : public VertexArray<OpenGLVertexArray> {
  public:
    OpenGLVertexArray();
    ~OpenGLVertexArray();

    void Bind();
    void Unbind();

    void AddVertexBuffer(VertexBuffer<OpenGLVertexBuffer>* vertexBuffer);

    void SetIndexBuffer(IndexBuffer<OpenGLIndexBuffer>* indexBuffer);

  private:
    GLuint m_vao;
    std::vector<VertexBuffer<OpenGLVertexBuffer>*> m_vertexBuffers;
    std::vector<IndexBuffer<OpenGLIndexBuffer>*> m_indexBuffers;

  };

  static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type) {
    switch (type) {
    case ShaderDataType::Float: return GL_FLOAT;
    case ShaderDataType::Float2: return GL_FLOAT;
    case ShaderDataType::Float3: return GL_FLOAT;
    case ShaderDataType::Float4: return GL_FLOAT;
    case ShaderDataType::Mat3: return GL_FLOAT;
    case ShaderDataType::Mat4: return GL_FLOAT;
    case ShaderDataType::Int: return GL_INT;
    case ShaderDataType::Int2: return GL_INT;
    case ShaderDataType::Int3: return GL_INT;
    case ShaderDataType::Int4: return GL_INT;
    case ShaderDataType::Bool: return GL_BOOL;
    }

    FC_CORE_ERROR("Unknown ShaderDataType!");
    return 0;
  }

}  // namespace ForgeCraft
