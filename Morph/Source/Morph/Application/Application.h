#pragma once

#include "Core/CoreMinimal.h"
#include "Window.h"

namespace Morph {

	class Application
	{
	public:
		void Run();

		void OnEvent();
	private:
		Scope<Window> m_Window;
	};

	Application* CreateApplication();
}