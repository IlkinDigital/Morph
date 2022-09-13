#pragma once

#include "Core/CoreMinimal.h"

namespace Morph {

	class Window
	{
	public:
		virtual void Init() = 0;
		virtual void Shutdown() = 0;

		virtual uint32 GetWidth()  const { return m_Width;  }
		virtual uint32 GetHeight() const { return m_Height; }
		
		Ref<Window> Create(uint32 width, uint32 height, bool vsync);
	protected:
		uint32 m_Width = 1920, m_Height = 1080;
		bool m_VSync = true;
	};
}
