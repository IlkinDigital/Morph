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
Include["Morph"] = "%{wks.location}/Morph/Source";

include "Morph"
include "MorphApp"
