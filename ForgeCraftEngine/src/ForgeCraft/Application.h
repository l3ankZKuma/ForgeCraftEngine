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
#include<ForgeCraft/Renderer/VertexArray.h>
#include<Platform/OpenGL/OpenGLVertexArray.h>

// Renderer
#include <ForgeCraft/Renderer/Renderer.h>
#include <ForgeCraft/Renderer/RenderCommand.h>

//Camera
#include "Renderer/Camera/Camera.h"
#include "Renderer/Camera/CameraManager.h"
#include "Renderer/Camera/Orthographic2DCamera.h"

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

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
   // CameraManager m_cameraManager;


    // Triangle
    OpenGLShader* m_shader;

    VBO* m_vbo;
    EBO* m_ebo;
    VAO* m_vao;

    GLfloat m_vertices[3 * 6] = {
      // positions        //color
      -0.5f, -0.5f, 0.0f, 0.0 , 1.0, 0.0,
      0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
      0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,
    };

    GLuint m_indices[3] = {
      0, 1, 2
    };

    OpenGLShader* m_shader2;
    VBO* m_vbo2;
    EBO* m_ebo2;
    VAO* m_vao2;

    GLfloat m_vertices2[3 * 6] = {
      // positions        // color
      -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
       0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f,
       0.0f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f,
    };

    GLuint m_indices2[3] = {
      0, 1, 2
    };

  };

  Application* CreateApplication();
}
