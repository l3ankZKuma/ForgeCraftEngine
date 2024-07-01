#pragma once

#include "ForgeCraft/Core.h"
#include "ForgeCraft/Events/Event.h"


namespace ForgeCraft {

	class FORGECRAFT_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
		virtual void OnEvent(Event& event) = 0;

		const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}

