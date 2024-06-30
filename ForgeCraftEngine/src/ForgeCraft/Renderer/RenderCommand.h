#pragma once

#include <ForgeCraft/Renderer/RendererAPI.h>
#include <ForgeCraft/Renderer/VertexArray.h>

#include<Platform/OpenGL/OpenGLRedererAPI.h>

namespace ForgeCraft {

  using VAO = VertexArray<OpenGLVertexArray>;

  class RenderCommand {
  public:

    inline static void SetClearColor(const glm::vec4 &color) {
      s_RendererAPI->SetClearColor(color);
    }

    inline static void Clear() {
      s_RendererAPI->Clear();
    }

    // Static method to draw indexed vertex array
    static void DrawIndexed(VAO *vertexArray) {
      s_RendererAPI->DrawIndexed(vertexArray);
    }

  private:
    inline static OpenGLRendererAPI* s_RendererAPI{ new OpenGLRendererAPI() };

  };



}

