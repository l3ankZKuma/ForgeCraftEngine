#include"fcpch.h"

#include"ForgeCraft/Core/Input.h"
#include"ForgeCraft/Application.h"


namespace ForgeCraft {

  bool Input::IsKeyPressed(KeyCode key) {
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetKey(window, TO_INT(key));
    return state == GLFW_PRESS || state == GLFW_REPEAT;
  }

  bool Input::IsMouseButtonPressed(MouseCode button) {
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetMouseButton(window, TO_INT(button));
    return state == GLFW_PRESS;
  }

  glm::vec2 Input::GetMousePosition() {
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    return { (float)xpos, (float)ypos };
  }



  glm::vec3 Input::GetMousePosition3D() {
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    return { (float)xpos, (float)ypos, 0.0f };
  }


  float Input::GetMouseX() {
    return GetMousePosition().x;
  }

  float Input::GetMouseY() {
    return GetMousePosition().y;
  }


  float Input::GetMouseZ() {
    return GetMousePosition3D().z;
  }

}