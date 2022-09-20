#include "Application.h"

#include "Window.h"
#include "Event/EventDispatcher.h"

namespace Morph {

	Application::Application(const std::string& name)
	{
		m_Window = Window::Create(name, 1920, 1080, true);

		m_Window->SetEventCallback(CALLBACK_BIND(OnEvent));
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<EventType::WindowClose>(EVENT_BIND(OnWindowClose));

		std::string eventName = event.GetName();
		MORPH_INFO(event.GetName());
	}

	bool Application::OnWindowClose()
	{
		m_Window->Shutdown();
		m_Running = false;

		return false;
	}

}