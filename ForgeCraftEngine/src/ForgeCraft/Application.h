#pragma once

#include "Core.h"
#include"ForgeCraft/Log.h"
#include"ForgeCraft/Events/ApplicationEvent.h"
#include"ForgeCraft/Window.h"
#include"ForgeCraft/Core/LayerStack.h"
#include "Application.h"


#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)


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

    inline Window& GetWindow() { return *m_window; }
    inline static Application& Get() { return *s_instance; }


    
  private:

    Window *m_window;
    LayerStack m_layerStack;


    bool m_running{ true };

    bool OnWindowClose(WindowCloseEvent& e);

  private:

    static Application* s_instance;

  };

  // To be defined in CLIENT
  Application* CreateApplication();



}
