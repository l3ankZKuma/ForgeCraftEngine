#include "fcpch.h"
#include "Application.h"

namespace ForgeCraft {

  Application* Application::s_instance = nullptr;

  Application::Application(){
    s_instance = this;
    m_window = WindowsWindow::Create();
    m_window->SetEventCallback(BIND_EVENT_FN(OnEvent));

    m_imguiLayer = new ImguiLayer();
    m_imguiLayer->OnAttach();

    //----------------------------------[Camera] ----------------------------------------

   // m_cameraManager.SetActiveCamera(m_camera);

    //----------------------------------(1)---------------------------------------------
    // Initialize the first shader
    m_shader = new OpenGLShader(R"(
      #version 330 core

      layout(location = 0) in vec3 aPos;
      layout(location = 1) in vec3 aColor;
      
      uniform mat4 vp;

      out vec3 color;

      void main() {
      gl_Position = /*projection*view*model*/vp * vec4(aPos, 1.0);
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

    m_vao = VAO::Create();

    // Create Vertex Buffer for the first triangle
    m_vbo = VBO::Create(m_vertices, sizeof(m_vertices));
    m_vbo->Bind();

    // Create Index Buffer for the first triangle
    const GLuint size = 3;
    m_ebo = EBO::Create(m_indices, size);
    m_ebo->Bind();

    BufferLayout layout = {
      {ShaderDataType::Float3, "aPos"},
      {ShaderDataType::Float3, "aColor"}
    };

    m_vbo->SetLayout(layout);

    m_vao->AddVertexBuffer(m_vbo);
    m_vao->SetIndexBuffer(m_ebo);
    //---------------------------------(2)----------------------------------------------
    // Initialize the second shader
    m_shader2 = new OpenGLShader(R"(
      #version 330 core

      layout(location = 0) in vec3 aPos;
      layout(location = 1) in vec3 aColor;

      uniform mat4 vp;  

      

      out vec3 color;

      void main() {
        gl_Position = /* projection*view*model*/vp * vec4(aPos, 1.0);
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

    m_vao2 = VAO::Create();

    // Create Vertex Buffer for the second triangle
    m_vbo2 = VBO::Create(m_vertices2, sizeof(m_vertices2));
    m_vbo2->Bind();

    // Create Index Buffer for the second triangle
    m_ebo2 = EBO::Create(m_indices2,size);
    m_ebo2->Bind();

    BufferLayout layout2 = {
      {ShaderDataType::Float3, "aPos"},
      {ShaderDataType::Float3, "aColor"}
    };

    m_vbo2->SetLayout(layout2);

    m_vao2->AddVertexBuffer(m_vbo2);
    m_vao2->SetIndexBuffer(m_ebo2);


   /* const auto& vp = std::visit([](auto&& camera) -> const auto& {
      return camera.GetViewProjectionMatrix();
      }, m_cameraManager.GetActiveCamera());*/

    const auto & vp = m_camera.GetViewProjectionMatrix();

    m_shader->Bind();
    m_shader->SetMat4("vp", vp);

    m_shader2->Bind();
    m_shader2->SetMat4("vp", vp);

    //--------------------------------------------------------------------------------
  }

  Application::~Application() {
    for (Layer* layer : m_layerStack) {
      layer->OnDetach();
      delete layer;
    }

    m_imguiLayer->OnDetach();



    delete m_imguiLayer;
    delete m_window;
    delete m_shader;
    delete m_vbo;
    delete m_ebo;
    delete m_vao;
    delete m_shader2;
    delete m_vbo2;
    delete m_ebo2;
    delete m_vao2;
  }

  void Application::OnEvent(Event& e) {
    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

    for (auto it = m_layerStack.end(); it != m_layerStack.begin(); ) {
      (*--it)->OnEvent(e);
      if (e.Handled)
        break;
    }
  }

  void Application::Run() {
    while (m_running) {
      
      RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
      RenderCommand::Clear();



      Renderer::BeginScene(m_camera);


      //----------------------------------------------------------------------------
      {


        Renderer::Submit(m_vao,m_shader);

        Renderer::Submit(m_vao2,m_shader2);


      }
      //----------------------------------------------------------------------------

      Renderer::EndScene();



      for (Layer* layer : m_layerStack) {
        layer->OnUpdate();
      }

      m_imguiLayer->Begin();
      m_imguiLayer->Render();
      m_imguiLayer->End();

      m_window->OnUpdate();
    }
  }

  bool Application::OnWindowClose(WindowCloseEvent& e) {
    m_running = false;
    return true;
  }

  void Application::PushLayer(Layer* layer) {
    m_layerStack.PushLayer(layer);
    layer->OnAttach();
  }

  void Application::PushOverlay(Layer* overlay) {
    m_layerStack.PushOverlay(overlay);
    overlay->OnAttach();
  }

}
