#pragma once

#include "Input/KeyCodes.h"
#include "Input/MouseCodes.h"


namespace Morph {

	enum class EventType
	{
		None,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseScrolled, MouseMoved,
		WindowClose, WindowResize
	};

	class Event
	{
	public:
		virtual const char* GetName()  const { return "EventType::None"; }
		virtual EventType GetEventType() const { return EventType::None; }

		bool Handled = false;
	};

#define EVENT_BASE_IMPL(eventType) virtual const char* GetName() const override { return #eventType; } \
									   virtual EventType GetEventType() const override { return eventType; }

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		EVENT_BASE_IMPL(EventType::WindowClose)
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(uint32 width, uint32 height)
			: m_Width(width), m_Height(height) {}

		uint32 GetWidth()  const { return m_Width;  }
		uint32 GetHeight() const { return m_Height; }

		EVENT_BASE_IMPL(EventType::WindowResize)
	private:
		uint32 m_Width, m_Height;
	};

	class KeyPressedEvent : public Event
	{
	public:
		KeyPressedEvent(Key keyCode, int repeatCount)
			: m_KeyCode(keyCode), m_RepeatCount(repeatCount) {}

		Key GetKeyCode() const { return m_KeyCode; }
		int GetRepeatCount() const { return m_RepeatCount; }

		EVENT_BASE_IMPL(EventType::KeyPressed)
	private:
		Key m_KeyCode;
		int m_RepeatCount; // for now 1 if repeats, 0 otherwise. TODO: Make count
	};

	class KeyReleasedEvent : public Event
	{
	public:
		KeyReleasedEvent(Key keyCode)
			: m_KeyCode(keyCode) {}

		Key GetKeyCode() const { return m_KeyCode; }

		EVENT_BASE_IMPL(EventType::KeyReleased)
	private:
		Key m_KeyCode;
	};

	class MouseButtonPressedEvent : public Event
	{
	public:
		MouseButtonPressedEvent(Mouse mouseButton)
			: m_MouseButton(mouseButton) {}

		Mouse GetMouseButton() const { return m_MouseButton; }

		EVENT_BASE_IMPL(EventType::MouseButtonPressed)
	private:
		Mouse m_MouseButton;
	};

	class MouseButtonReleasedEvent : public Event
	{
	public:
		MouseButtonReleasedEvent(Mouse mouseButton)
			: m_MouseButton(mouseButton) {}

		Mouse GetMouseButton() const { return m_MouseButton; }

		EVENT_BASE_IMPL(EventType::MouseButtonReleased)
	private:
		Mouse m_MouseButton;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_OffsetX(xOffset), m_OffsetY(yOffset) {}

		float GetOffsetX() const { return m_OffsetX; }
		float GetOffsetY() const { return m_OffsetY; }

		EVENT_BASE_IMPL(EventType::MouseScrolled)
	private:
		float m_OffsetX, m_OffsetY;
	};

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float xPos, float yPos)
			: m_PosX(xPos), m_PosY(yPos) {}

		float GetPosX() const { return m_PosX; }
		float GetPosY() const { return m_PosY; }

		EVENT_BASE_IMPL(EventType::MouseMoved)
	private:
		float m_PosX, m_PosY;
	};
}