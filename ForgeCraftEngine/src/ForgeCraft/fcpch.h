#pragma once

// Standard Library
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <cstring>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include<array>
#include<numeric>


// Meta-programming
#include <type_traits>
#include <tuple>
#include <variant>
#include <optional>


#ifdef FC_PLATFORM_WINDOWS
  #include <Windows.h>
#endif


// Third Party
#include <glad/glad.h>
#include <GLFW/glfw3.h>


//imgui
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
