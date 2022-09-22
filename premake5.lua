workspace "Morph"
    architecture "x64"
    startproject "MorphApp" -- Generic for different apps

    configurations 
    {
        "Debug",
        "Release",
        "Distribution"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

Include = {}
Include["Morph"] = "%{wks.location}/Morph/Source"
Include["GLFW"] = "%{wks.location}/ThirdParty/GLFW/include"
Include["glad"] = "%{wks.location}/ThirdParty/glad/include"
Include["ImGui"] = "%{wks.location}/ThirdParty/ImGui"

Library = {}
Library["GLFW"] = "GLFW"
Library["glad"] = "glad"
Library["ImGui"] = "ImGui"

include "ThirdParty/GLFW"
include "ThirdParty/glad"
include "ThirdParty/ImGui"

include "Morph"
include "MorphApp"
