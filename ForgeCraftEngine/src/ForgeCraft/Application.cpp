#include "fcpch.h"
#include "Application.h"

namespace ForgeCraft {

  Application* Application::s_instance = nullptr;

  Application::Application() {
    s_instance = this;
    m_window = WindowsWindow::Create();  // Changed to initialize the raw pointer directly
    m_window->SetEventCallback(BIND_EVENT_FN(OnEvent));
  }

  Application::~Application() {
    delete m_window;  // Make sure the pointer is properly deleted
  }

  void Application::OnEvent(Event& e) {
    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

    FC_CORE_INFO("{0}", e.ToString());

    // Handle events in reverse order for layers
    for (auto it = m_layerStack.end(); it != m_layerStack.begin(); ) {
      (*--it)->OnEvent(e);
      if (e.Handled)
        break;
    }
  }

  void Application::Run() {
    while (m_running) {
      m_window->Clear();

      for (Layer* layer : m_layerStack) {
        layer->OnUpdate();
      }

#if 0

      const auto mousePos = Input::GetMousePosition();
      const auto x = mousePos.x;
      const auto y = mousePos.y;

      FC_CORE_TRACE("Mouse: {0}, {1}", x, y);

#endif

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
