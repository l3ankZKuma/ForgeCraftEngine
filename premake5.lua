
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
IncludeDir["glad"] = "ForgeCraftEngine/vendor/glad/include"
IncludeDir["GLFW"] = "ForgeCraftEngine/vendor/GLFW/include"
IncludeDir["spdlog"] = "ForgeCraftEngine/vendor/spdlog/include"
IncludeDir["imgui"] = "ForgeCraftEngine/vendor/imgui"
IncludeDir["glm"] = "ForgeCraftEngine/vendor/glm"


-- Include the projects
group "Dependencies"
    include "ForgeCraftEngine/vendor/GLFW"
    include "ForgeCraftEngine/vendor/glad"
    include "ForgeCraftEngine/vendor/imgui"
group ""

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
        "%{IncludeDir.glad}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.imgui}",
        "%{IncludeDir.glm}"
    }

    links
    {
        "glad",
        "GLFW",
        "imgui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "off"
        systemversion "latest"

        defines
        {
            "FC_PLATFORM_WINDOWS",
            "FC_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "FC_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "FC_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "FC_DIST"
        runtime "Release"
        optimize "On"

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
        "ForgeCraftEngine/src",
        "%{IncludeDir.imgui}"
    }

    links
    {
        "ForgeCraftEngine",
        "imgui"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "off"
        systemversion "latest"

        defines
        {
            "FC_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "FC_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "FC_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "FC_DIST"
        runtime "Release"
        optimize "On"