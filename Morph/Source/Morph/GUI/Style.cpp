#include "Style.h"

#include <imgui.h>

namespace Morph::GUI {

	static ImGuiIO& s_IO = ImGui::GetIO();

	void Style::PushFont(const Font& font)
	{
		ImGui::PushFont(font.Get());
	}

	void Style::PopFont()
	{
		ImGui::PopFont();
	}

	void Style::SetDefaultFont(const Font& font)
	{
		s_IO.FontDefault = font.Get();
	}

}