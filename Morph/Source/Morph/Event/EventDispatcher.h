#pragma once

#include "Event.h"

namespace Morph {

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<EventType Ty>
		bool Dispatch(std::function<bool()> func)
		{
			if (m_Event.GetEventType() == Ty && !m_Event.Handled)
			{
				m_Event.Handled = func();
				return true;
			}
			
			return false;
		}
	private:
		Event& m_Event;
	};
	
}
