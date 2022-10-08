#include "Style.h"

#include <imgui.h>

namespace Morph {

	void Style::PushFont(const Font& font)
	{
		ImGui::PushFont(font.GetNative());
	}

	void Style::PopFont()
	{
		ImGui::PopFont();
	}

	void Style::SetDefaultFont(const Font& font)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.FontDefault = font.GetNative();
	}

}