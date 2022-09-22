#pragma once

#include "Event/Event.h"
#include "Window.h"

#include "GUI/ImGui/ImGuiLayer.h"

namespace Morph {

	class Application
	{
	public:
		Application(const std::string& name);

		static Application& Get() { return *s_Instance; }
		Window& GetWindow() { return *m_Window; }
		
		virtual void OnUpdate() {}
		virtual void OnDrawGUI() {}
		void OnEvent(Event& event);

		bool OnWindowClose();
		void Run();

	private:
		bool m_Running = true;
		Scope<Window> m_Window;

		Ref<ImGuiLayer> m_GUILayer;

		inline static Application* s_Instance = nullptr;
	};
}