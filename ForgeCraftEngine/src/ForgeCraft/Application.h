#pragma once

#include <ForgeCraft/Core.h>
#include <ForgeCraft/Log.h>
#include <ForgeCraft/Events/ApplicationEvent.h>
#include <ForgeCraft/Core/LayerStack.h>
#include <ForgeCraft/Core/Input.h>
#include <ForgeCraft/Imgui/ImguiLayer.h>
#include <Platform/Windows/WindowsWindow.h>

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace ForgeCraft {
  class WindowsWindow;
  class ImguiLayer;
}

namespace ForgeCraft {

  class FORGECRAFT_API Application {
  public:
    Application();
    virtual ~Application();

    void Run();
    void OnEvent(Event& e);

    void PushLayer(Layer* layer);
    void PushOverlay(Layer* overlay);

    inline WindowsWindow& GetWindow() { return *m_window; }
    inline static Application& Get() { return *s_instance; }

  private:
    WindowsWindow* m_window;
    ImguiLayer* m_imguiLayer;

    LayerStack m_layerStack;
    bool m_running = true;
    bool OnWindowClose(WindowCloseEvent& e);

    static Application* s_instance;

    // Triangle
    unsigned int m_vao, m_vbo, m_ebo;
    unsigned int m_shaderProgram;
    float m_vertices[18] = {
      // positions        //color
      -0.5f, -0.5f, 0.0f, 0.0 , 1.0, 0.0,
      0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
      0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f
    };
    unsigned int m_indices[3] = {
      0, 1, 2
    };

    // Shader source code
    const char* vertexShaderSource = R"(
      #version 330 core
      layout(location = 0) in vec3 aPos;
      layout(location = 1 ) in vec3 aColor;

      out vec3 ourColor;
      void main() {
          gl_Position = vec4(aPos, 1.0);
          ourColor = aColor;
      }
    )";
    const char* fragmentShaderSource = R"(
      #version 330 core
      
      in vec3 ourColor;

      out vec4 FragColor;
      void main() {
          FragColor = vec4(ourColor, 1.0);
      }
    )";

    void InitShaders();
  };

  Application* CreateApplication();
}
