#pragma once

#include "Core/CoreMinimal.h"
#include <imgui.h>

namespace Morph {

	static const uint16 s_FontWeightCount = 3;

	enum class FontWeight : uint16
	{ 
		Light, Normal, Bold 
	};

	class Font
	{
	public:
		Font(const std::string& name)
			: m_Name(name) {}

		void Set(FontWeight weight, const Filepath& path);
		void SwitchWeight(FontWeight weight);

		ImFont* GetNative() const; 
	private:
	private:
		std::string m_Name;
		FontWeight m_CurrentWeight = FontWeight::Normal;
		ImFont* m_Fonts[s_FontWeightCount]{};

		friend class Style;
	};
}