#include "fcpch.h"
#include "OpenGLVertexArray.h"

namespace ForgeCraft {

  OpenGLVertexArray::OpenGLVertexArray() {
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
  }

  OpenGLVertexArray::~OpenGLVertexArray() {
    glDeleteVertexArrays(1, &m_vao);
  }

  void OpenGLVertexArray::Bind() {  
    glBindVertexArray(m_vao);
  }

  void OpenGLVertexArray::Unbind() {
    glBindVertexArray(0);
  }

  void OpenGLVertexArray::AddVertexBuffer(VertexBuffer<OpenGLVertexBuffer>* vertexBuffer) {
    glBindVertexArray(m_vao);
    vertexBuffer->Bind();
    const auto& layout = vertexBuffer->GetLayout();
    const auto& elements = layout.GetElements();
    uint32_t index = 0;
    for (const auto& element : elements) {
      glEnableVertexAttribArray(index);
      glVertexAttribPointer(index,
        element.GetComponentCount(),
        ShaderDataTypeToOpenGLBaseType(element.Type),
        element.Normalized ? GL_TRUE : GL_FALSE,
        layout.GetStride(),
        (const void*)element.Offset);
      index++;
    }

    m_vertexBuffers.push_back(vertexBuffer);
  }

  void OpenGLVertexArray::SetIndexBuffer(IndexBuffer<OpenGLIndexBuffer>* indexBuffer) {
    glBindVertexArray(m_vao);
    indexBuffer->Bind();
  }

  template class VertexArray<OpenGLVertexArray>;  // Explicit instantiation

}  // namespace ForgeCraft
