#pragma once

namespace ForgeCraft {


  template<typename Derived>
  class  Shader {

  public:

    ~Shader() = default;

    void Bind() const {
      static_cast<const Derived*>(this)->Bind();
    }

    void UnBind() const {
      static_cast<const Derived*>(this)->UnBind();
    }

  protected:

    GLuint m_rendererID;
  };

}