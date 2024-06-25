#include "fcpch.h"
#include "WindowsWindow.h"

#define CAST_INT(value) static_cast<int>(value)

namespace ForgeCraft {

  static void GLFWErrorCallback(int error, const char* description) {
    std::cerr << "GLFW Error (" << error << "): " << description << '\n';
  }

  WindowsWindow::WindowsWindow(const WindowProps& props) noexcept {
    Init(props);
  }

  WindowsWindow::~WindowsWindow() noexcept {
    Shutdown();
  }

  void WindowsWindow::Init(const WindowProps& props) noexcept {
    m_data.Title = props.mTitle;
    m_data.Width = props.mWidth;
    m_data.Height = props.mHeight;

    if (!s_GLFWInitialized) {
      if (glfwInit() == GLFW_TRUE) [[likely]] {
        glfwSetErrorCallback(GLFWErrorCallback);
        s_GLFWInitialized = true;
        }
      else [[unlikely]] {
        std::cerr << "Failed to initialize GLFW!" << '\n';
        return;
        }
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(CAST_INT(props.mWidth), CAST_INT(props.mHeight), m_data.Title.c_str(), nullptr, nullptr);
    if (m_window) [[likely]] {
      glfwMakeContextCurrent(m_window);
      glfwSwapInterval(1); // Enable vsync
      glfwSetWindowUserPointer(m_window, &m_data);
      SetVSync(true);

      if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) [[likely]] {
        // GLAD initialized successfully
        }
      else [[unlikely]] {
        std::cerr << "Failed to initialize GLAD!" << '\n';
        }
      }
    else [[unlikely]] {
      std::cerr << "Failed to create GLFW window!" << '\n';
      }

      // Set GLFW callbacks here

      glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
      data.Width = CAST_INT(width);
      data.Height = CAST_INT(height);

      WindowResizeEvent event(CAST_INT(width), CAST_INT(height));
      data.EventCallback(event);
        });

    glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
      WindowCloseEvent event;
      data.EventCallback(event);
      });

    glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

      switch (action) {
      case GLFW_PRESS: {
        KeyPressedEvent event(key, 0);
        data.EventCallback(event);
        break;
      }
      case GLFW_RELEASE: {
        KeyReleasedEvent event(key);
        data.EventCallback(event);
        break;
      }
      case GLFW_REPEAT: {
        KeyPressedEvent event(key, 1);
        data.EventCallback(event);
        break;
      }
      
      }

      });

    glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

      switch (action) {
      case GLFW_PRESS: {
        MouseButtonPressedEvent event(button);
        data.EventCallback(event);
        break;
      }
      case GLFW_RELEASE: {
        MouseButtonReleasedEvent event(button);
        data.EventCallback(event);
        break;
      }
      }
      });

    glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos) {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

      MouseMovedEvent event((float)xpos, (float)ypos);
      data.EventCallback(event);
      });

    glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset) {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

      MouseScrolledEvent event((float)xoffset, (float)yoffset);
      data.EventCallback(event);
      });
  }

  void WindowsWindow::Shutdown() noexcept {
    if (m_window) [[likely]] {
      glfwDestroyWindow(m_window);
      }
  }

  void WindowsWindow::OnUpdate() {
    glfwPollEvents();
    glfwSwapBuffers(m_window);
  }

  void WindowsWindow::SetVSync(bool enabled) {
    glfwSwapInterval(enabled ? 1 : 0);
    m_data.VSync = enabled;
  }

  inline unsigned int WindowsWindow::GetWidth() const {
    return m_data.Width;
  }

  inline unsigned int WindowsWindow::GetHeight() const {
    return m_data.Height;
  }

  inline void WindowsWindow::SetEventCallback(const EventCallbackFn& callback) {
    m_data.EventCallback = callback;
  }

  inline bool WindowsWindow::IsVSync() const {
    return m_data.VSync;
  }

  inline void* WindowsWindow::GetNativeWindow() const {
    return m_window;
  }

  inline Window* Window::Create(const WindowProps& props) {
    return new WindowsWindow(props);
  }

} // namespace ForgeCraft
