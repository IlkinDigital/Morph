project "Morph"
    language "C++"
    cppdialect "C++20"
    kind "StaticLib"
    staticruntime "off"

    targetdir ("../Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("../Binaries-Int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "Source/**.h",
        "Source/**.cpp"
    }

    includedirs
    {
        "%{Include.Morph}",
        "Source/Morph"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "MORPH_PLATFORM_WINDOWS",
            "GLFW_INCLUDE_NONE"
        }

    filter "configurations:Debug"
        defines "MORPH_CONFIG_DEBUG"
        runtime "Debug"
        optimize "off"
        symbols "on"

    filter "configurations:Release"
        defines "MORPH_CONFIG_RELEASE"
        runtime "Release"
        optimize "on"
        symbols "on"

    filter "configurations:Distribution"
        defines "MORPH_CONFIG_DISTRIBUTION"
        runtime "Release"
        optimize "full"
        symbols "off"