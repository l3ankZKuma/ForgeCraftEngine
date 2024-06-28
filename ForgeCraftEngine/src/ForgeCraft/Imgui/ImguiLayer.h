#pragma once

#include "ForgeCraft/Core.h"
#include"ForgeCraft/Application.h"


//imgui
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"



namespace ForgeCraft {

  class FORGECRAFT_API ImguiLayer{
  public:

    ImguiLayer();
    ~ImguiLayer();

    void OnAttach();
    void OnDetach();

    void OnEvent(Event& event);

    void Update();
    void Render();

    void End();
    void Begin();



  private:
    float m_time = 0.0f;
  };

}