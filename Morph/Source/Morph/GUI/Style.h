#pragma once

#include "FontLibrary.h"

namespace Morph::GUI {

	class Style
	{
	public:
		static void PushFont(const Font& font);
		static void PopFont();

		static void SetDefaultFont(const Font& font);
	};

}
