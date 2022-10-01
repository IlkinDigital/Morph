#include "PanelStack.h"

namespace Morph {

	void PanelStack::PushPanel(const Ref<GUI::Panel>& panel)
	{
		if (m_InsertIndex > m_Stack.size())
		{
			MORPH_ERROR("Failed to push panel, insertion index out of range.");
			return;
		}

		m_Stack.insert(m_Stack.begin() + m_InsertIndex, panel);
	}

	void PanelStack::PushOverlay(const Ref<GUI::Panel>& overlay)
	{
		m_Stack.insert(m_Stack.begin(), overlay);
		m_InsertIndex++;
	}
}