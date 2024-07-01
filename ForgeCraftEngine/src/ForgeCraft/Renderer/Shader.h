#pragma once

#include<glm/glm.hpp>

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


    void SetInt(const char* name, int value)  {
      static_cast<Derived*>(this)->SetIntImpl(name, value);
    }

    void SetIntArray(const char* name, int* values, uint32_t count) {
      static_cast<Derived*>(this)->SetIntArrayImpl(name, values, count);
    }

    void SetFloat(const char* name, float value) {
      static_cast<Derived*>(this)->SetFloatImpl(name, value);
    }

    void SetFloat2(const char* name, const glm::vec2& value) {
      static_cast<Derived*>(this)->SetFloat2Impl(name, value);
    }

    void SetFloat3(const char* name, const glm::vec3& value) {
      static_cast<Derived*>(this)->SetFloat3Impl(name, value);
    }

    void SetFloat4(const char* name, const glm::vec4& value) {
      static_cast<Derived*>(this)->SetFloat4Impl(name, value);
    }

    void SetMat4(const char* name, const glm::mat4& value) {
      static_cast<Derived*>(this)->SetMat4Impl(name, value);
    }
    

  };

}