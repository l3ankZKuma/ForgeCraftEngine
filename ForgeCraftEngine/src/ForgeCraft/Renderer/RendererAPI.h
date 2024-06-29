#pragma once

namespace ForgeCraft {

  template<typename Derived>
  class RendererAPI {
  public:
    enum class API {
      None = 0,
      OpenGL = 1
    };

    ~RendererAPI() = default;

    void Init() {
      static_cast<Derived*>(this)->Init();
    }

    void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
      static_cast<Derived*>(this)->SetViewport(x, y, width, height);
    }

    void SetClearColor(float r, float g, float b, float a) {
      static_cast<Derived*>(this)->SetClearColor(r, g, b, a);
    }

    void Clear() {
      static_cast<Derived*>(this)->Clear();
    }

    void DrawIndexed() {
      static_cast<Derived*>(this)->DrawIndexed();
    }

    inline static API GetAPI() { return s_API; }

  protected:
    inline static API s_API{ API::OpenGL };
  };


}
