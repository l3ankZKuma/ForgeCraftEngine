#include "fcpch.h"
#include "RendererAPI.h"


#include<ForgeCraft/Renderer/Buffer.h>
#include "Platform/OpenGL/OpenGLVertexArray.h"
#include<Platform/OpenGL/OpenGLBuffer.h>


namespace ForgeCraft {


  template class VertexArray<OpenGLVertexArray>;
  template class VertexBuffer<OpenGLVertexBuffer>;
  template class IndexBuffer<OpenGLIndexBuffer>;
}
