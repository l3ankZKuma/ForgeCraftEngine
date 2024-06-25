#pragma once

#include <ForgeCraft/Window.h>
#include<ForgeCraft/Events/ApplicationEvent.h>
#include<ForgeCraft/Events/KeyEvent.h>
#include<ForgeCraft/Events/MouseEvent.h>


namespace ForgeCraft {

  class WindowsWindow : public Window {
  public:
    WindowsWindow(const WindowProps& props) noexcept;
    virtual ~WindowsWindow() noexcept;

    void OnUpdate() override;

    inline unsigned int GetWidth() const override;
    inline unsigned int GetHeight() const override;

    // Window attributes
    inline void SetEventCallback(const EventCallbackFn& callback) override;
    void SetVSync(bool enabled) override;
    inline bool IsVSync() const override;

    inline void* GetNativeWindow() const override;

  private:
    void Init(const WindowProps& props) noexcept;
    void Shutdown() noexcept;

    GLFWwindow* m_window;

    struct WindowData {
      std::string Title;
      unsigned int Width, Height;
      bool VSync;
      EventCallbackFn EventCallback;
    };

    WindowData m_data;

    inline static bool s_GLFWInitialized{ false };
  };

} // namespace ForgeCraft
