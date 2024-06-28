#pragma once

#include "ForgeCraft/Core.h"
#include "ForgeCraft/Events/Event.h"


namespace ForgeCraft {

	class FORGECRAFT_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void Render() {};
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}

