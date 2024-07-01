// Application.h

#pragma once

#include <ForgeCraft/Core.h>
#include <ForgeCraft/Log.h>
#include <ForgeCraft/Events/ApplicationEvent.h>
#include <ForgeCraft/Core/LayerStack.h>
#include <ForgeCraft/Core/Input.h>
#include <ForgeCraft/Imgui/ImguiLayer.h>
#include <Platform/Windows/WindowsWindow.h>

// Shader
#include <Platform/OpenGL/OpenGLShader.h>

// Vertex Buffer
#include <ForgeCraft/Renderer/Buffer.h>
#include <Platform/OpenGL/OpenGLBuffer.h>

// Vertex Array
#include <ForgeCraft/Renderer/VertexArray.h>
#include <Platform/OpenGL/OpenGLVertexArray.h>

// Renderer
#include <ForgeCraft/Renderer/Renderer.h>
#include <ForgeCraft/Renderer/RenderCommand.h>

// Camera
#include <ForgeCraft/Renderer/Camera/Camera.h>
#include <ForgeCraft/Renderer/Camera/CameraManager.h>
#include <ForgeCraft/Renderer/Camera/Orthographic2DCamera.h>


namespace ForgeCraft {
  using VAO = VertexArray<OpenGLVertexArray>;
  using VBO = VertexBuffer<OpenGLVertexBuffer>;
  using EBO = IndexBuffer<OpenGLIndexBuffer>;
}

namespace ForgeCraft {
  class WindowsWindow;
  class ImguiLayer;
  class Orthographic2DCamera;
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

    bool &GetRunning() { return m_running; }

    inline WindowsWindow& GetWindow() { return *m_window; }
    inline static Application& Get() { return *s_instance; }

  private:
    WindowsWindow* m_window;
    ImguiLayer* m_imguiLayer;

    LayerStack m_layerStack;
    bool m_running = true;
    bool OnWindowClose(WindowCloseEvent& e);

    static Application* s_instance;

    // Camera
    Orthographic2DCamera m_camera{ -1.6f, 1.6f, -0.9f, 0.9f };
  };

  Application * CreateApplication();
}
