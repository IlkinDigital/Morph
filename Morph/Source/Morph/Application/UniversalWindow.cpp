#include "UniversalWindow.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Morph {

	UniversalWindow::UniversalWindow(uint32 width, uint32 height, bool vSync)
	{
		m_Width = width;
		m_Height = height;
		m_VSync = vSync;

		Init();
	}

	void UniversalWindow::Init()
	{
		int init = glfwInit();
		MORPH_ASSERT(init, "Couldn't initialize GLFW window!");
	}

}