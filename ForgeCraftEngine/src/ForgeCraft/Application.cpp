#include "fcpch.h"
#include "Application.h"

namespace ForgeCraft {

  Application* Application::s_instance = nullptr;

  Application::Application() {
    s_instance = this;
    m_window = WindowsWindow::Create();
    m_window->SetEventCallback(BIND_EVENT_FN(OnEvent));

    m_imguiLayer = new ImguiLayer();
    m_imguiLayer->OnAttach();

    m_shader = new OpenGLShader(R"(
      #version 330 core

      layout(location = 0) in vec3 aPos;
      layout(location = 1) in vec3 aColor;

      out vec3 color;

      void main() {
        gl_Position = vec4(aPos, 1.0);
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

    // Initialize Vertex Array Object
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);

    // Create Vertex Buffer
    m_vbo = VertexBuffer<OpenGLVertexBuffer>::Create(m_vertices, 18);
    m_vbo->Bind();


    // Create Index Buffer
    m_ebo = IndexBuffer<OpenGLIndexBuffer>::Create(m_indices, 3);
    m_ebo->Bind();

    // Set Vertex Attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);  // Unbind VAO
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
      m_window->Clear();

      // Render the triangle
      m_shader->Bind();
      glBindVertexArray(m_vao);
      glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
      m_shader->UnBind();

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
