#pragma once


#include"Core.h"
#include"spdlog/spdlog.h"
#include"spdlog/sinks/stdout_color_sinks.h"
#include<memory>



namespace ForgeCraft {

  class FORGECRAFT_API Log {


  public:

    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
      return s_CoreLogger;
    }

    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
      return s_ClientLogger;
    }

  private:
    
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;






  };


};


// Core log macros

#define FC_CORE_ERROR(...)  ::ForgeCraft::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FC_CORE_WARN(...)   ::ForgeCraft::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FC_CORE_INFO(...)   ::ForgeCraft::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FC_CORE_TRACE(...)  ::ForgeCraft::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FC_CORE_FATAL(...)  ::ForgeCraft::Log::GetCoreLogger()->fatal(__VA_ARGS__)


// Client log macros

#define FC_ERROR(...)  ::ForgeCraft::Log::GetClientLogger()->error(__VA_ARGS__)
#define FC_WARN(...)   ::ForgeCraft::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FC_INFO(...)   ::ForgeCraft::Log::GetClientLogger()->info(__VA_ARGS__)
#define FC_TRACE(...)  ::ForgeCraft::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FC_FATAL(...)  ::ForgeCraft::Log::GetClientLogger()->fatal(__VA_ARGS__)
