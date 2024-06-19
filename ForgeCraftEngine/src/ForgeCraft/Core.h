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