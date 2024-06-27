#pragma once

#include "ForgeCraft/Core.h"
#include "ForgeCraft/Events/Event.h"

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

  template <typename Derived>
  class Window {
  public:
    using EventCallbackFn = std::function<void(Event&)>;

    virtual ~Window() = default;

    void OnUpdate() {
      static_cast<Derived*>(this)->OnUpdateImpl();
    }

    void Clear() {
      static_cast<Derived*>(this)->ClearImpl();
    }

    unsigned int GetWidth() const {
      return static_cast<const Derived*>(this)->GetWidthImpl();
    }

    unsigned int GetHeight() const {
      return static_cast<const Derived*>(this)->GetHeightImpl();
    }

    void SetEventCallback(const EventCallbackFn& callback) {
      static_cast<Derived*>(this)->SetEventCallbackImpl(callback);
    }

    void SetVSync(bool enabled) {
      static_cast<Derived*>(this)->SetVSyncImpl(enabled);
    }

    bool IsVSync() const {
      return static_cast<const Derived*>(this)->IsVSyncImpl();
    }

    void* GetNativeWindow() const {
      return static_cast<const Derived*>(this)->GetNativeWindowImpl();
    }

    static Derived* Create(const WindowProps& props = WindowProps()) {
      return new Derived(props);
    }
  };
}
