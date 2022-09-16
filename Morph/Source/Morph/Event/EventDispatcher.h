#pragma once

#include "Event.h"

namespace Morph {

	class EventDispatcher
	{
	public:
		template<typename Ty, typename Fn>
		bool Dispatch(Event event, Fn func)
		{
			if (event.GetEventType() == Ty && !event.Handled)
			{
				func(event);
				event.Handled = true;
				return true;
			}
			
			return false;
		}
	};
	
}
