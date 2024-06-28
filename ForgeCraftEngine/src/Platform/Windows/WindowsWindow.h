#pragma once

#include <ForgeCraft/Window.h>
#include <ForgeCraft/Events/ApplicationEvent.h>
#include <ForgeCraft/Events/KeyEvent.h>
#include <ForgeCraft/Events/MouseEvent.h>



//Renderer
#include<Platform/OpenGL/OpenGLContext.h>

namespace ForgeCraft {

  class WindowsWindow : public Window<WindowsWindow> {
  public:
    WindowsWindow(const WindowProps& props) noexcept;
    ~WindowsWindow() noexcept;

    void OnUpdateImpl();
    void ClearImpl();

    unsigned int GetWidthImpl() const;
    unsigned int GetHeightImpl() const;

    void SetEventCallbackImpl(const EventCallbackFn& callback);
    void SetVSyncImpl(bool enabled);
    bool IsVSyncImpl() const;

    void* GetNativeWindowImpl() const;

  private:
    void Init(const WindowProps& props) noexcept;
    void Shutdown() noexcept;


#if 1
    OpenGLContext* m_context;
#endif

    GLFWwindow* m_window;

    struct WindowData {
      std::string Title;
      unsigned int Width, Height;
      bool VSync;
      EventCallbackFn EventCallback;
    };

    WindowData m_data;

    static bool s_GLFWInitialized;
  };
}