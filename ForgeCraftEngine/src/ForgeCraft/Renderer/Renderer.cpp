#include "fcpch.h"
#include "Renderer.h"

namespace ForgeCraft {


  void Renderer::BeginScene(const Orthographic2DCamera& camera) {

    s_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();

  }

  void Renderer::EndScene() {

  }

  void Renderer::Submit(OpenGLVertexArray * vertexArray,OpenGLShader *shader,const glm::mat4 &transform) {
    shader->Bind();

    shader->SetMat4("model",transform);
    shader->SetMat4("vp", s_SceneData->ViewProjectionMatrix);

    vertexArray->Bind();
    RenderCommand::DrawIndexed(vertexArray);
    shader->UnBind();
    
  }

}