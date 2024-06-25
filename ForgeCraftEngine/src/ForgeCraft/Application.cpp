// Application.cpp
#include "fcpch.h"
#include "Application.h"

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace ForgeCraft {

  Application::Application() {
    m_window = Window::Create();
    m_window->SetEventCallback(BIND_EVENT_FN(OnEvent));
  }

  Application::~Application() {
    delete m_window;
  }

  void Application::OnEvent(Event& _E) {

     EventDispatcher dispatcher(_E);
     dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));


     FC_CORE_INFO("{0}",_E.ToString());
  }

  void Application::Run() {
    while (m_running) {


      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
      m_window->OnUpdate();
    }
  }

  bool Application::OnWindowClose(WindowCloseEvent& e) {
    m_running = false;
    return true;
  }



}
