#include "Application.h"

#include "Window.h"

namespace Morph {

	Application::Application(const std::string& name)
	{
		m_Window = Window::Create(name, 1920, 1080, true);

		m_Window->SetEventCallback([&](Event& event)
			{
				OnEvent(event);
			});
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& event) const
	{
		std::string eventName = event.GetName();
		MORPH_INFO(event.GetName());
	}

}