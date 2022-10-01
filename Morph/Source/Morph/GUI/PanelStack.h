#pragma once

#include "Panel.h"

namespace Morph {

	class PanelStack
	{
	public:
		using Iterator = std::vector<Ref<GUI::Panel>>::iterator;
	public:
		PanelStack() = default;

		void PushPanel(const Ref<GUI::Panel>& panel);
		void PushOverlay(const Ref<GUI::Panel>& overlay);

		Iterator begin() { return m_Stack.begin(); }
		Iterator end()   { return m_Stack.end();   }
	private:
		std::vector<Ref<GUI::Panel>> m_Stack;
		uint16 m_InsertIndex = 0;
	};

}