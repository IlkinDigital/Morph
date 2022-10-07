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