#pragma once

#include "Event/Event.h"

#include <functional>

namespace Morph {

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;
	public:
		virtual ~Window() {}

		virtual void Init() = 0;
		virtual void Shutdown() = 0;
		virtual void OnUpdate() = 0;

		virtual void* GetNativeWindow() = 0;

		virtual uint32 GetWidth()  const = 0;
		virtual uint32 GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		
		static Scope<Window> Create(const std::string& title, uint32 width, uint32 height, bool vsync);
	};
}
