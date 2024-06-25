#include "fcpch.h"
#include "ImguiLayer.h"


namespace ForgeCraft {

  ImguiLayer::ImguiLayer()
    : Layer("ImguiLayer")
  {

  }
  ImguiLayer::~ImguiLayer()
  {

  }

  void ImguiLayer::OnAttach()
  {
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

    io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
    io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
    io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
    io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
    io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
    io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
    io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
    io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
    io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
    io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
    io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
    io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
    io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
    io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
    io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
    io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
    io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
    io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
    io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
    io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
    io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;


    const auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());


    ImGui_ImplOpenGL3_Init("#version 410");
    ImGui_ImplGlfw_InitForOpenGL(window, true);
  }

  void ImguiLayer::OnDetach()
  {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

  }


  void ImguiLayer::OnUpdate()
  {


    ImGuiIO& io = ImGui::GetIO();
    Application& app = Application::Get();
    io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

    float time = (float)glfwGetTime();
    io.DeltaTime = m_time > 0.0 ? (time - m_time) : (1.0f / 60.0f);
    m_time = time;


    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();



    static bool show = true;
    ImGui::ShowDemoWindow(&show);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  }

  void ImguiLayer::OnEvent(Event& e)
  {
    // Add debug statements
    std::cout << "Event Received: " << e.ToString() << std::endl;

    ImGuiIO& io = ImGui::GetIO();

    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<KeyPressedEvent>([this, &io](KeyPressedEvent& event) {
      io.KeysDown[event.GetKeyCode()] = true;
      return false;
      });

    dispatcher.Dispatch<KeyReleasedEvent>([this, &io](KeyReleasedEvent& event) {
      io.KeysDown[event.GetKeyCode()] = false;
      return false;
      });

    dispatcher.Dispatch<MouseButtonPressedEvent>([this, &io](MouseButtonPressedEvent& event) {
      io.MouseDown[event.GetMouseButton()] = true;
      return false;
      });

    dispatcher.Dispatch<MouseButtonReleasedEvent>([this, &io](MouseButtonReleasedEvent& event) {
      io.MouseDown[event.GetMouseButton()] = false;
      return false;
      });

    dispatcher.Dispatch<MouseMovedEvent>([this, &io](MouseMovedEvent& event) {
      io.MousePos = ImVec2(event.GetX(), event.GetY());
      return false;
      });

    dispatcher.Dispatch<MouseScrolledEvent>([this, &io](MouseScrolledEvent& event) {
      io.MouseWheelH += event.GetXOffset();
      io.MouseWheel += event.GetYOffset();
      return false;
      });


  }


}
