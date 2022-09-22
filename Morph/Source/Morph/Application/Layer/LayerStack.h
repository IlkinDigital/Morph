#pragma once

#include "Layer.h"

namespace Morph {

	class LayerStack
	{
	public:
		LayerStack() = default;

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		std::vector<Layer*> m_Stack;
		uint16 m_InsertIndex = 0;
	};

}