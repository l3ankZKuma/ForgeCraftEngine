#pragma once

#include "ForgeCraft/Core.h"
#include "ForgeCraft/Events/Event.h"

namespace ForgeCraft {

  class FORGECRAFT_API Layer {
  public:
    Layer(const std::string& name = "Layer");
    virtual ~Layer() = default;

    // Virtual functions to be overridden by derived layers
    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnUpdate() {}
    virtual void OnImGuiRender() {}
    virtual void OnEvent(Event& event) {}  // Ensure this line is correct

    // Get the name of the layer
    const std::string& GetName() const { return m_DebugName; }

  protected:
    std::string m_DebugName; // Debug name for the layer
  };

}
