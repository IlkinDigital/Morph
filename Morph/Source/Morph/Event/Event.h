#pragma once

#include "Core/CoreMinimal.h"

namespace Morph {

	enum EventType
	{
		KeyPressed,
		MousePressed,
		WindowCloseEvent
	};

	class Event
	{
	public:
		virtual const String& GetName()  const = 0;
		virtual EventType GetEventType() const = 0;
	};

	
}