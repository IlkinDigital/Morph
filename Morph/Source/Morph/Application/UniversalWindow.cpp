#include "UniversalWindow.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Morph {

#ifdef MORPH_PLATFORM_WINDOWS
	Scope<Window> Window::Create(const std::string& title, uint32 width, uint32 height, bool vsync)
	{
		return CreateScope<UniversalWindow>(title, width, height, vsync);
	}
#endif

	static int s_GLFWInitialized = 0;

	UniversalWindow::UniversalWindow(const std::string& title, uint32 width, uint32 height, bool vSync)
	{
		m_Data.Title = title;
		m_Data.Width = width;
		m_Data.Height = height;
		m_Data.VSync = vSync;

		Init();
	}

	void UniversalWindow::SetVSync(bool enabled)
	{
		glfwSwapInterval(enabled);
		m_Data.VSync = enabled;
	}

	void UniversalWindow::Init()
	{
		if (!s_GLFWInitialized)
		{
			s_GLFWInitialized = glfwInit();
			MORPH_ASSERT(s_GLFWInitialized, "Failed to initialize GLFW!");
		}

		m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(m_Window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MORPH_ASSERT(status, "Failed to intialize glad!");

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(m_Data.VSync);

		/*
		* Set up callbacks
		*/

		// Window Close
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);

				WindowCloseEvent event;

				data->Callback(event);
			});

		// Window Resize
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);

			WindowResizeEvent event(width, height);

			data->Callback(event);
		});

		// Key
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event((Key)key, 0);
					data->Callback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event((Key)key, 1);
					data->Callback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event((Key)key);
					data->Callback(event);
					break;
				}
				}
			});

		// Mouse
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event((Mouse)button);
					data->Callback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event((Mouse)button);
					data->Callback(event);
					break;
				}
				}
			});


		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event(xoffset, yoffset);
				data->Callback(event);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
			{
				WindowData* data = (WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event(xpos, ypos);
				data->Callback(event);
			});
	}

	void UniversalWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void UniversalWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

}