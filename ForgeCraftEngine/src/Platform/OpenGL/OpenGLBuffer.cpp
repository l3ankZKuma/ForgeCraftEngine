#include "fcpch.h"
#include "OpenGLBuffer.h"

namespace ForgeCraft {

  OpenGLVertexBuffer::OpenGLVertexBuffer(GLfloat* data, GLuint size) {
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, size*sizeof(GLfloat), data, GL_STATIC_DRAW);
  }

  OpenGLVertexBuffer::~OpenGLVertexBuffer() {
    glDeleteBuffers(1, &m_vbo);
  }

  void OpenGLVertexBuffer::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  }

  void OpenGLVertexBuffer::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }

  OpenGLIndexBuffer::OpenGLIndexBuffer(GLuint* data, GLuint size) {
    glGenBuffers(1, &m_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size*sizeof(GLfloat), data, GL_STATIC_DRAW);
  }

  OpenGLIndexBuffer::~OpenGLIndexBuffer() {
    glDeleteBuffers(1, &m_ebo);
  }

  void OpenGLIndexBuffer::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
  }

  void OpenGLIndexBuffer::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  }

}
