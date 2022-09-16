#pragma once

#include "Core/CoreMinimal.h"

namespace Morph {

	enum EventType
	{
		KeyPressed,
		MouseButtonPressed, MouseMoved,
		WindowCloseEvent
	};

	class Event
	{
	public:
		virtual const std::string& GetName()  const = 0;
		virtual EventType GetEventType() const = 0;

		bool Handled = false;
	};

	
}