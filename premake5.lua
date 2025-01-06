-- For premake5 documentation, see their WIKI on GitHub: https://github.com/premake/premake-core/wiki

workspace "Pluto"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Pluto"
    location "Pluto"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" ..outputdir .. "/%{prj.name}")
    objdir ("bin-int/" ..outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/ThirdParty/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "PLUTO_PLATFORM_WINDOWS",
            "PLUTO_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter { "system:windows", "action:vs2022" }
        buildoptions { "/utf-8" }

    filter "configurations:Debug"
        defines "PLUTO_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PLUTO_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "PLUTO_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" ..outputdir .. "/%{prj.name}")
    objdir ("bin-int/" ..outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs
    {
        "Pluto/ThirdParty/spdlog/include",
        "Pluto/Source"
    }

    links
    {
        "Pluto"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "PLUTO_PLATFORM_WINDOWS"
        }

    filter { "system:windows", "action:vs2022" }
        buildoptions { "/utf-8" }

    filter "configurations:Debug"
        defines "PLUTO_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PLUTO_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "PLUTO_DIST"
        optimize "On"