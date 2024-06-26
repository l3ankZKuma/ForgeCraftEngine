#pragma once


#include<ForgeCraft/Renderer/RendererAPI.h>

#include<ForgeCraft/Renderer/VertexArray.h>
#include<Platform/OpenGL/OpenGLVertexArray.h>



namespace ForgeCraft {



  class  OpenGLRendererAPI: RendererAPI<OpenGLRendererAPI>  {

  public:

    void Init() ;
    void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
    void SetClearColor(const glm::vec4 & color);
    void Clear();
    void DrawIndexed(OpenGLVertexArray *vertexArray );

  };

}