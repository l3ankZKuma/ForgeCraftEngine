#pragma once

namespace ForgeCraft {

  template<typename Derived>
  class GraphicsContext
  {
  public:
    GraphicsContext() = default;
    ~GraphicsContext() = default;

    void Init() {
      static_cast<Derived*>(this)->InitImpl();
    }

    void SwapBuffers() {
      static_cast<Derived*>(this)->SwapBuffersImpl();
    }
  };

}
