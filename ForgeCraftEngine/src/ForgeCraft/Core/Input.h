#pragma once

#include"ForgeCraft/fcpch.h"
#include "ForgeCraft/Core/KeyCodes.h"
#include "ForgeCraft/Core/MouseCodes.h"
#include "ForgeCraft/Core.h"


namespace ForgeCraft {

	class FORGECRAFT_API Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();

		// Additional functions for 3D input handling
		static glm::vec3 GetMousePosition3D();
		static float GetMouseZ();


	};
}
