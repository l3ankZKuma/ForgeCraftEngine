#include "fcpch.h"
#include "Renderer.h"

namespace ForgeCraft {


  void Renderer::BeginScene() {



  }

  void Renderer::EndScene() {

  }


  void Renderer::Submit(VAO * vertexArray) {
    RenderCommand::DrawIndexed(vertexArray);
  }
}