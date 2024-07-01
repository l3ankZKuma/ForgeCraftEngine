#pragma once

#include <ForgeCraft/Renderer/RendererAPI.h>
#include<Platform/OpenGL/OpenGLVertexArray.h>

#include<Platform/OpenGL/OpenGLRedererAPI.h>

namespace ForgeCraft {


  class FORGECRAFT_API RenderCommand {
  public:

    inline static void SetClearColor(const glm::vec4 &color) {
      s_RendererAPI->SetClearColor(color);
    }

    inline static void Clear() {
      s_RendererAPI->Clear();
    }

    // Static method to draw indexed vertex array
    static void DrawIndexed(OpenGLVertexArray *vertexArray) {
      s_RendererAPI->DrawIndexed(vertexArray);
    }

  private:
    inline static OpenGLRendererAPI* s_RendererAPI{ new OpenGLRendererAPI() };

  };



}

