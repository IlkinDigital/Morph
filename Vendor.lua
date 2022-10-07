Include = {}
Include["Morph"] = "%{MorphDir}/Morph/Source"
Include["GLFW"] = "%{MorphDir}/ThirdParty/GLFW/include"
Include["glad"] = "%{MorphDir}/ThirdParty/glad/include"
Include["ImGui"] = "%{MorphDir}/ThirdParty/ImGui"

Library = {}
Library["GLFW"] = "GLFW"
Library["glad"] = "glad"
Library["ImGui"] = "ImGui"

include "ThirdParty/GLFW"
include "ThirdParty/glad"
include "ThirdParty/ImGui"

include "Morph"