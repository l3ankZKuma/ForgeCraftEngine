#pragma once

#include"ForgeCraft/Core.h"
#include"ForgeCraft/Events/Event.h"


namespace ForgeCraft {

  struct WindowProps {
    std::string mTitle;
    unsigned int mWidth;
    unsigned int mHeight;

    WindowProps(const std::string& title = "ForgeCraft Engine",
      unsigned int width = 1280,
      unsigned int height = 720)
      : mTitle(title), mWidth(width), mHeight(height) {}


  };

  class FORGECRAFT_API Window {
  public:

    using EventCallbackFn = std::function<void(Event&)>;

    virtual ~Window() {}

    virtual void OnUpdate() = 0;

    virtual unsigned int GetWidth() const = 0;
    virtual unsigned int GetHeight() const = 0;

    // Window attributes
    virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
    virtual void SetVSync(bool enabled) = 0;
    virtual bool IsVSync() const = 0;

    virtual void* GetNativeWindow() const = 0;

    static Window* Create(const WindowProps& props = WindowProps());


  };

}