project "Morph"
    language "C++"
    cppdialect "C++20"
    kind "StaticLib"
    staticruntime "off"

    targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/Binaries-Int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "Source/**.h",
        "Source/**.cpp"
    }

    includedirs
    {
        "%{Include.Morph}",
        "Source/Morph",
        "%{Include.GLFW}",
        "%{Include.glad}"
    }

    links
    {
        "%{Library.GLFW}",
        "%{Library.glad}"
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