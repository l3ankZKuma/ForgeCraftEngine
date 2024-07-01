#include <ForgeCraft.h>
#include <array>

class Layers : public ForgeCraft::Layer {
public:
  Layers() : Layer("Example") {
    for (size_t i = 0; i < m_shader.size(); ++i) {
      m_shader[i] = nullptr;
      m_vao[i] = nullptr;
      m_vbo[i] = nullptr;
      m_ebo[i] = nullptr;
    }
    InitializeShaders();
    InitializeBuffers();
  }

  ~Layers() {
    OnDetach();
  }

  void OnAttach() override {}

  void OnDetach() override {
    for (size_t i = 0; i < m_vao.size(); ++i) {
      if (m_shader[i]) { delete m_shader[i]; m_shader[i] = nullptr; }
      if (m_vao[i]) { delete m_vao[i]; m_vao[i] = nullptr; }
      if (m_vbo[i]) { delete m_vbo[i]; m_vbo[i] = nullptr; }
      if (m_ebo[i]) { delete m_ebo[i]; m_ebo[i] = nullptr; }
    }
  }

  void Update() override {
    ForgeCraft::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
    ForgeCraft::RenderCommand::Clear();

    ForgeCraft::Renderer::BeginScene(m_camera);

    for (size_t i = 0; i < m_vao.size(); ++i) {
      if (m_shader[i] && m_vao[i]) {
        m_shader[i]->Bind();
        ForgeCraft::Renderer::Submit(m_vao[i], m_shader[i]);
      }
    }

    ForgeCraft::Renderer::EndScene();
  }

  void Render() override {}

  void OnEvent(ForgeCraft::Event& event) override {
    ForgeCraft::EventDispatcher dispatcher(event);

    dispatcher.Dispatch<ForgeCraft::KeyPressedEvent>(
      [this](ForgeCraft::KeyPressedEvent& e) {
        if (e.GetKeyCode() == GLFW_KEY_LEFT) {
          const auto& vp = m_camera.GetPosition();
          m_camera.SetPosition({ vp.x + 0.1f, vp.y, vp.z });
        }
        if (e.GetKeyCode() == GLFW_KEY_RIGHT) {
          const auto& vp = m_camera.GetPosition();
          m_camera.SetPosition({ vp.x - 0.1f, vp.y, vp.z });
        }
        if (e.GetKeyCode() == GLFW_KEY_UP) {
          const auto& vp = m_camera.GetPosition();
          m_camera.SetPosition({ vp.x, vp.y + 0.1f, vp.z });
        }
        if (e.GetKeyCode() == GLFW_KEY_DOWN) {
          const auto& vp = m_camera.GetPosition();
          m_camera.SetPosition({ vp.x, vp.y - 0.1f, vp.z });
        }
        return false;
      }
    );
  }

private:
  void InitializeShaders() {
    m_shader[0] = new ForgeCraft::OpenGLShader(R"(
      #version 330 core
      layout(location = 0) in vec3 aPos;
      layout(location = 1) in vec3 aColor;
      uniform mat4 vp;
      out vec3 color;
      void main() {
        gl_Position = vp * vec4(aPos, 1.0);
        color = aColor;
      }
    )", R"(
      #version 330 core
      in vec3 color;
      out vec4 fragColor;
      void main() {
        fragColor = vec4(color, 1.0);
      }
    )");

    m_shader[1] = new ForgeCraft::OpenGLShader(R"(
      #version 330 core
      layout(location = 0) in vec3 aPos;
      layout(location = 1) in vec3 aColor;
      uniform mat4 vp;
      out vec3 color;
      void main() {
        gl_Position = vp * vec4(aPos, 1.0);
        color = aColor;
      }
    )", R"(
      #version 330 core
      in vec3 color;
      out vec4 fragColor;
      void main() {
        fragColor = vec4(color, 1.0);
      }
    )");
  }

  void InitializeBuffers() {
    m_vao[0] = ForgeCraft::VAO::Create();
    m_vbo[0] = ForgeCraft::VBO::Create(m_vertices1.data(), sizeof(m_vertices1));
    m_ebo[0] = ForgeCraft::EBO::Create(m_indices1.data(), m_indices1.size());

    m_vbo[0]->SetLayout({
      { ForgeCraft::ShaderDataType::Float3, "aPos" },
      { ForgeCraft::ShaderDataType::Float3, "aColor" }
      });

    m_vao[0]->AddVertexBuffer(m_vbo[0]);
    m_vao[0]->SetIndexBuffer(m_ebo[0]);

    m_vao[1] = ForgeCraft::VAO::Create();
    m_vbo[1] = ForgeCraft::VBO::Create(m_vertices2.data(), sizeof(m_vertices2));
    m_ebo[1] = ForgeCraft::EBO::Create(m_indices2.data(), m_indices2.size());

    m_vbo[1]->SetLayout({
      { ForgeCraft::ShaderDataType::Float3, "aPos" },
      { ForgeCraft::ShaderDataType::Float3, "aColor" }
      });

    m_vao[1]->AddVertexBuffer(m_vbo[1]);
    m_vao[1]->SetIndexBuffer(m_ebo[1]);

    const auto& vp = m_camera.GetViewProjectionMatrix();
    m_shader[0]->Bind();
    m_shader[0]->SetMat4("vp", vp);

    m_shader[1]->Bind();
    m_shader[1]->SetMat4("vp", vp);
  }

  ForgeCraft::Orthographic2DCamera m_camera{ -1.6f, 1.6f, -0.9f, 0.9f };

  std::array<ForgeCraft::OpenGLShader*, 2> m_shader;
  std::array<ForgeCraft::OpenGLVertexArray*, 2> m_vao;
  std::array<ForgeCraft::OpenGLVertexBuffer*, 2> m_vbo;
  std::array<ForgeCraft::OpenGLIndexBuffer*, 2> m_ebo;

  std::array<GLfloat, 18> m_vertices1 = {
    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
    0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f
  };

  std::array<GLuint, 3> m_indices1 = { 0, 1, 2 };

  std::array<GLfloat, 18> m_vertices2 = {
    -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
    0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f,
    0.0f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f
  };

  std::array<GLuint, 3> m_indices2 = { 0, 1, 2 };
};

class Sandbox : public ForgeCraft::Application {
public:
  Sandbox() {
    PushLayer(new Layers());
  }
  ~Sandbox() {
    
  }
};

ForgeCraft::Application* ForgeCraft::CreateApplication() {
  return new Sandbox();
}
