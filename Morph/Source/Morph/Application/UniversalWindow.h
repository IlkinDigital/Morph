#pragma once

#include "Window.h"

struct GLFWwindow;

namespace Morph {

	class UniversalWindow : public Window
	{
	public:
		UniversalWindow(const std::string& title, uint32 width, uint32 height, bool vSync);

		virtual void Init() override;
		virtual void Shutdown() override;

		virtual void OnUpdate() override;

		virtual uint32 GetWidth() const override  { return m_Data.Width;  }
		virtual uint32 GetHeight() const override { return m_Data.Height; }

		virtual void SetVSync(bool enabled) override;
		virtual void SetEventCallback(const EventCallbackFn& callback) override { m_Data.Callback = callback; }
	private:
		struct WindowData
		{
			int Width, Height;
			bool VSync;
			std::string Title;

			EventCallbackFn Callback;
		};

		WindowData m_Data;

		GLFWwindow* m_Window;
	};

}