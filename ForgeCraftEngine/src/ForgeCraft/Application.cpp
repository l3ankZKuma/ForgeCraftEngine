#include "fcpch.h"
#include "Application.h"


namespace ForgeCraft {

  Application* Application::s_instance = nullptr;

  Application::Application() {

   
    s_instance = this;  


    m_window = Window::Create();
    m_window->SetEventCallback(BIND_EVENT_FN(OnEvent));



  }

  Application::~Application() {
    delete m_window;
  }

  void Application::OnEvent(Event& _E) {

    EventDispatcher dispatcher(_E);
    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

    FC_CORE_INFO("{0}", _E.ToString());

    // Handle events in reverse order for layers
    for (auto it = m_layerStack.end(); it != m_layerStack.begin(); ) {
      (*--it)->OnEvent(_E);  // Ensure this line calls OnEvent with Event&
      if (_E.Handled)
        break;
    }
  }

  void Application::Run() {
    while (m_running) {

      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      for (Layer* layer : m_layerStack) {
        layer->OnUpdate();
      }

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
