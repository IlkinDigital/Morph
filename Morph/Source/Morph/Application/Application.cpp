#include "Application.h"

#include "Window.h"
#include "Event/EventDispatcher.h"

#include "GUI/Layout.h"

#include <glad/glad.h>
#include <imgui.h>

namespace Morph {

	Application::Application(const std::string& name)
	{
		s_Instance = this;

		m_Window = Window::Create(name, 1920, 1080, true);
		m_Window->SetEventCallback(CALLBACK_BIND(OnEvent));
		m_GUILayer = CreateRef<ImGuiLayer>(); 
	}

	void Application::Run()
	{
		m_GUILayer->OnAttach();

		while (m_Running)
		{
			glClearColor(0.8, 0.2, 0.2, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);

			OnUpdate();

			m_GUILayer->Begin();


			ImGui::ShowDemoWindow();


			m_GUILayer->End();

			m_Window->OnUpdate();
		}

		m_GUILayer->OnDetach();
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<EventType::WindowClose>(EVENT_BIND(OnWindowClose));

		if (!event.Handled)
			m_GUILayer->OnEvent(event);

		//std::string eventName = event.GetName();
		//MORPH_INFO(event.GetName());
	}

	bool Application::OnWindowClose()
	{
		m_Running = false;

		return true;
	}

}