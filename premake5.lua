workspace "ForgeCraftEngine"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "ForgeCraftEngine/Vendor/GLFW/include"
IncludeDir["spdlog"] = "ForgeCraftEngine/Vendor/spdlog/include"

-- Ensure GLFW is included
include "ForgeCraftEngine/Vendor/GLFW"

-- ForgeCraftEngine Project
project "ForgeCraftEngine"
    location "ForgeCraftEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


    pchheader "fcpch.h"
    pchsource "ForgeCraftEngine/src/fcpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.spdlog}"              
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }



    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "FC_PLATFORM_WINDOWS",
            "FC_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "FC_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "FC_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "FC_DIST"
        optimize "On"

-- Sandbox Project
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "ForgeCraftEngine/vendor/spdlog/include",
        "ForgeCraftEngine/src"
    }

    links
    {
        "ForgeCraftEngine"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "FC_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "FC_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "FC_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "FC_DIST"
        optimize "On"
