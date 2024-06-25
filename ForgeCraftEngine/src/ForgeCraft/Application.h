#pragma once

#include "Core.h"
#include"ForgeCraft/Log.h"
#include"ForgeCraft/Events/ApplicationEvent.h"
#include"ForgeCraft/Window.h"
#include"ForgeCraft/Core/LayerStack.h"

namespace ForgeCraft {

  class FORGECRAFT_API Application
  {
    public:

    Application();
    virtual ~Application();


    //Method
    void Run();
    void OnEvent(Event& e);

    void PushLayer(Layer* layer);
    void PushOverlay(Layer* overlay);

    
  private:

    Window *m_window;
    LayerStack m_layerStack;


    bool m_running{ true };

    bool OnWindowClose(WindowCloseEvent& e);

  };

  // To be defined in CLIENT
  Application* CreateApplication();



}
