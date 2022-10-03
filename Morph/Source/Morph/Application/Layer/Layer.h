#pragma once

#include "Event/Event.h"

namespace Morph {
	
	class Layer
	{
	public:
		Layer(const char* name)
			: m_Name(name) {}

		const char* GetName() const { return m_Name; }

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(float timestep) {}
		virtual void OnRenderGUI() {}
		virtual void OnEvent(Event& event) {}
	protected:
		const char* m_Name;
	};

}