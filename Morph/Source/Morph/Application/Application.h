#pragma once

#include "Event/Event.h"
#include "Window.h"

namespace Morph {

	class Application
	{
	public:
		Application(const std::string& name);

		void Run();

		void OnEvent(Event& event) const;
	private:
		bool m_Running = true;
		Scope<Window> m_Window;
	};
}