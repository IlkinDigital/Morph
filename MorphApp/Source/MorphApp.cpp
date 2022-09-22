#include "Morph/Application/EntryPoint.h"

#include <imgui.h>

using namespace Morph;

class MorphApp : public Application
{
public:
	MorphApp(const std::string& name)
		: Application(name) {}

	virtual void OnDrawGUI() override
	{
		ImGui::Begin("Test Window");

		ImGui::Text("Test text...");

		ImGui::End();
	}

	virtual void OnUpdate() override
	{
	}
};

Application* CreateApplication()
{
	return new MorphApp("Morph Application");
}