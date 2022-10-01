#include <Application/EntryPoint.h>
#include <GUI/PanelStack.h>
#include <GUI/Layout.h>

#include "LogPanel.h"

using namespace Morph;

class MorphApp : public Application
{
public:
	MorphApp(const std::string& name)
		: Application(name) 
	{
		m_PanelStack.PushPanel(CreateRef<LogPanel>());
		m_PanelStack.PushPanel(CreateRef<LogPanel>());
		m_PanelStack.PushPanel(CreateRef<LogPanel>());
		m_PanelStack.PushPanel(CreateRef<LogPanel>());
	}

	virtual void OnDrawGUI() override
	{
		GUI::Layout::BeginDockspace();

		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("View"))
			{
				for (auto& panel : m_PanelStack)
				{
					if (ImGui::MenuItem(panel->GetName(), panel->IsOpen() ? "Close" : "Open"))
						panel->Open();
				}

				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}

		for (auto& panel : m_PanelStack)
		{
			panel->OnRenderGUI();
		}

		GUI::Layout::EndDockspace();
	}

	virtual void OnUpdate() override
	{

	}
private:
	PanelStack m_PanelStack;
};

Application* CreateApplication()
{
	return new MorphApp("Morph Application");
}