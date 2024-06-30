#pragma once

#include <ForgeCraft/Core.h>
#include <ForgeCraft/Renderer/VertexArray.h>
#include <Platform/OpenGL/OpenGLBuffer.h>

namespace ForgeCraft {

  using VBO = VertexBuffer<OpenGLVertexBuffer>;
  using EBO = IndexBuffer<OpenGLIndexBuffer>;


  class FORGECRAFT_API OpenGLVertexArray : public VertexArray<OpenGLVertexArray> {
  public:
    OpenGLVertexArray();
    ~OpenGLVertexArray();

    void Bind();
    void Unbind();

    void AddVertexBuffer(VBO* vertexBuffer);
    void SetIndexBuffer(EBO* indexBuffer);

    const std::vector<VBO*> & GetVertexBuffer() const  {
      return m_vertexBuffers;
    }

    const EBO *  GetIndexBuffer() const {
      return m_indexBuffers;
    }

  private:
    GLuint m_vao;
    std::vector<VBO*> m_vertexBuffers;
    EBO *  m_indexBuffers;
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
    default: FC_CORE_ERROR("Unknown ShaderDataType!"); return 0;
    }
  }

}  // namespace ForgeCraft
