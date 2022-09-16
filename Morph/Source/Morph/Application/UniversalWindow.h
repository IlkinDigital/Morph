#pragma once

#include "Window.h"

namespace Morph {

	class UniversalWindow : public Window
	{
	public:
		UniversalWindow(uint32 width, uint32 height, bool vSync);

		virtual void Init() override;
	};

}