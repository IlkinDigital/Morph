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

MorphDir = ".."

include "Vendor.lua"
include "MorphApp"
