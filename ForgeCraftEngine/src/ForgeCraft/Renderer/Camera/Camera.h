#pragma once

#include<glm/glm.hpp>



namespace ForgeCraft {

  template<typename Derived>
  class Camera {
  public:
    
    ~Camera() = default;

    void SetPosition(const glm::vec3& position) {
      static_cast<Derived*>(this)->SetPosition(position);
    }
    
    const glm::vec4 &GetProjectionMatrix() const {
      return static_cast<const Derived*>(this)->GetProjectionMatrix();
    }

    const glm::vec4 &GetViewMatrix() const {
      return static_cast<const Derived*>(this)->GetViewMatrix();
    }

    const glm::vec4 &GetViewProjectionMatrix() const {
      return static_cast<const Derived*>(this)->GetViewProjectionMatrix();
    }

    const glm::vec3 &GetPosition() const {
      return static_cast<const Derived*>(this)->GetPosition();
    }



  };

}