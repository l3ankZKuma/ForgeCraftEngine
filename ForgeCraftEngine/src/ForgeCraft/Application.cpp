// Application.cpp

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
  }

  Application::~Application() {
    for (Layer* layer : m_layerStack) {
      layer->OnDetach();
    }

    m_imguiLayer->OnDetach();
    delete m_imguiLayer;
    delete m_window;
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

      for (Layer* layer : m_layerStack) {
        layer->Update();
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
