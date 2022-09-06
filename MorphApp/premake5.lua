project "MorphApp"
    location "MorphApp"
    language "C++"
    cppdialect "C++20"
    kind "ConsoleApp"
    staticruntime "off"

    targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("Binaries-Int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs 
    {
        "%{prj.name}/Source",
        "Morph"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "MORPH_PLATFORM_WINDOWS"
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
