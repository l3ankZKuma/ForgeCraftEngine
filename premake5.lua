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
IncludeDir["EASTL"] = "ForgeCraftEngine/vendor/EASTL/include"
IncludeDir["EABase"] = "ForgeCraftEngine/vendor/EASTL/test/packages/EABase/include/Common"
IncludeDir["EAAssert"] = "ForgeCraftEngine/vendor/EASTL/test/packages/EAAssert/include"
IncludeDir["EASTLTest"] = "ForgeCraftEngine/vendor/EASTL/test/packages/EASTLTest/include"

-- Include the projects
group "Dependencies"
    include "ForgeCraftEngine/vendor/GLFW"
    include "ForgeCraftEngine/vendor/glad"
    include "ForgeCraftEngine/vendor/imgui"
group ""

project "EASTL"
    location "ForgeCraftEngine/vendor/EASTL"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "ForgeCraftEngine/vendor/EASTL/source/**.cpp",
        "ForgeCraftEngine/vendor/EASTL/include/**.h"
    }

    includedirs
    {
        "ForgeCraftEngine/vendor/EASTL/include",
        "ForgeCraftEngine/vendor/EASTL/test/packages/EABase/include/Common",
        "ForgeCraftEngine/vendor/EASTL/test/packages/EAAssert/include",
        "ForgeCraftEngine/vendor/EASTL/test/packages/EASTLTest/include"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines "EASTL_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "EASTL_RELEASE"
        runtime "Release"
        optimize "on"

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
        "%{IncludeDir.glm}",
        "%{IncludeDir.EASTL}",
        "%{IncludeDir.EABase}",
        "%{IncludeDir.EAAssert}",
        "%{IncludeDir.EASTLTest}"
    }

    links
    {
        "glad",
        "GLFW",
        "imgui",
        "EASTL",
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
        "%{IncludeDir.imgui}",
        "%{IncludeDir.EASTL}",
        "%{IncludeDir.EABase}",
        "%{IncludeDir.EAAssert}",
        "%{IncludeDir.EASTLTest}"
    }

    links
    {
        "ForgeCraftEngine",
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
