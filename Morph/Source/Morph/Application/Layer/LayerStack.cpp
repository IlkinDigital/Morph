#include "LayerStack.h"

namespace Morph {

	void LayerStack::PushLayer(Layer* layer)
	{
		if (m_InsertIndex > m_Stack.size())
		{
			MORPH_ERROR("Failed to push layer, insertion index out of range.");
			return;
		}

		m_Stack.insert(m_Stack.begin() + m_InsertIndex, layer);
	}

	void LayerStack::PushOverlay(Layer* layer)
	{
		m_Stack.insert(m_Stack.begin(), layer);
		m_InsertIndex++;
	}

	

}