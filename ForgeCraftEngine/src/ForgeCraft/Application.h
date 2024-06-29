#pragma once

#include <ForgeCraft/Core.h>
#include <ForgeCraft/Log.h>
#include <ForgeCraft/Events/ApplicationEvent.h>
#include <ForgeCraft/Core/LayerStack.h>
#include <ForgeCraft/Core/Input.h>
#include <ForgeCraft/Imgui/ImguiLayer.h>
#include <Platform/Windows/WindowsWindow.h>
#include <Platform/OpenGL/OpenGLShader.h>
#include <ForgeCraft/Renderer/Buffer.h>
#include <Platform/OpenGL/OpenGLBuffer.h>

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
    GLuint m_vao;
    OpenGLShader* m_shader;

    VertexBuffer<OpenGLVertexBuffer>* m_vbo;
    IndexBuffer<OpenGLIndexBuffer>* m_ebo;


    GLfloat m_vertices[3 * 6] = {
      // positions        //color
      -0.5f, -0.5f, 0.0f, 0.0 , 1.0, 0.0,
      0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
      0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,


    };
    GLuint m_indices[3] = {
      0, 1, 2
    };
  };

  Application* CreateApplication();
}
