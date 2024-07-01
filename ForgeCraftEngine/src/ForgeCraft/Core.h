#pragma once

#ifdef FC_PLATFORM_WINDOWS
  #ifdef FC_BUILD_DLL
    #define FORGECRAFT_API __declspec(dllexport)
  #else
    #define FORGECRAFT_API __declspec(dllimport)
  #endif
#else
  #error ForgeCraft only supports Windows!
#endif

#define BIT(x) (1 << x)
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
