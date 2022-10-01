#pragma once

#include "Application/Layer/Layer.h"

namespace Morph {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer()
			: Layer("ImGuiLayer") {}

		void OnAttach() override;
		void OnDetach() override;
		void OnRenderGUI() override;
		void OnEvent(Event& event) override;

		void Begin();
		void End();

		void SetVastThemeColors();

		bool BlockEvents = false;
	};

}
