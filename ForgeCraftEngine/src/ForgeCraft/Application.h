#pragma once

#include "Core.h"
#include"ForgeCraft/Log.h"
#include"ForgeCraft/Events/ApplicationEvent.h"
#include"ForgeCraft/Window.h"

namespace ForgeCraft {

  class FORGECRAFT_API Application
  {
    public:

    Application();
    virtual ~Application();


    //Method
    void Run();
    void OnEvent(Event& e);
    
  private:

    Window *m_window;

    bool m_running{ true };

    bool OnWindowClose(WindowCloseEvent& e);

  };

  // To be defined in CLIENT
  Application* CreateApplication();



}
