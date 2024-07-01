#pragma once

#include <variant>
#include "Orthographic2DCamera.h"
#include "PerspectiveCamera.h"

namespace ForgeCraft {

  using ActiveCamera = std::variant<Orthographic2DCamera>;

  class CameraManager {
  public:
    CameraManager() = default;
    ~CameraManager() = default;

    // Copy constructor
    CameraManager(const CameraManager& other) : m_activeCamera(other.m_activeCamera) {}

    // Move constructor
    CameraManager(CameraManager&& other) noexcept : m_activeCamera(std::move(other.m_activeCamera)) {}

    // Copy assignment operator
    CameraManager& operator=(const CameraManager& other) {
      if (this != &other) {
        m_activeCamera = other.m_activeCamera;
      }
      return *this;
    }

    // Move assignment operator
    CameraManager& operator=(CameraManager&& other) noexcept {
      if (this != &other) {
        m_activeCamera = std::move(other.m_activeCamera);
      }
      return *this;
    }

    void SetActiveCamera(const ActiveCamera& camera) {
      m_activeCamera = camera;
    }

    const ActiveCamera& GetActiveCamera() const {
      return m_activeCamera;
    }

    template<typename CameraType>
    CameraType& GetCamera() {
      return std::get<CameraType>(m_activeCamera);
    }

    template<typename CameraType>
    const CameraType& GetCamera() const {
      return std::get<CameraType>(m_activeCamera);
    }

  private:
    ActiveCamera m_activeCamera;
  };

}
