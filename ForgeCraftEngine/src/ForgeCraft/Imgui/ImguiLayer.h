#pragma once


#include "ForgeCraft/Core/Layer.h"

#include "ForgeCraft/Events/ApplicationEvent.h"
#include "ForgeCraft/Events/KeyEvent.h"
#include "ForgeCraft/Events/MouseEvent.h"

#include"ForgeCraft/Application.h"


namespace ForgeCraft {



  class FORGECRAFT_API ImguiLayer : public Layer
  {
  public:
    ImguiLayer();
    ~ImguiLayer();

    void OnAttach();
    void OnDetach();
    void OnUpdate();
    void OnEvent(Event& e);

  private:
    
    float m_time;

  };
}