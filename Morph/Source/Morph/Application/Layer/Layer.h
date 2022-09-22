#pragma once

#include "Event/Event.h"

namespace Morph {
	
	class Layer
	{
	public:
		Layer(const char* name)
			: m_Name(name) {}

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnDrawGUI() {}
		virtual void OnEvent(Event& event) {}
	private:
		const char* m_Name;
	};

}