#include <ForgeCraft.h>

class Layers : public ForgeCraft::Layer {
public:
  Layers() : Layer("Example") {}
  ~Layers() = default;

  void Update() override {
    ForgeCraft::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
    ForgeCraft::RenderCommand::Clear();

    ForgeCraft::Renderer::BeginScene(m_camera);

    //----------------------------------------------------------------------------
    {
      // Renderer::Submit(m_vao1, m_shader1);
      // Renderer::Submit(m_vao2, m_shader2);
    }
    //----------------------------------------------------------------------------

    ForgeCraft::Renderer::EndScene();
  }

private:
  ForgeCraft::VAO m_vao1;
  ForgeCraft::VAO m_vao2;

  //ForgeCraft::OpenGLShader m_shader1;
  //ForgeCraft::OpenGLShader m_shader2;

  ForgeCraft::Orthographic2DCamera m_camera{ -1.6f, 1.6f, -0.9f, 0.9f };

  // CameraManager m_cameraManager;
};

class Sandbox : public ForgeCraft::Application {
public:
  Sandbox() {}
  ~Sandbox() {}
};

ForgeCraft::Application* ForgeCraft::CreateApplication() {
  return new Sandbox();
}
