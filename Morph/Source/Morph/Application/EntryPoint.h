#pragma once

#include "Application.h"

extern Morph::Application* CreateApplication();

int main()
{
	Morph::Application* app = CreateApplication();

	app->Run();

	delete app;

	MORPH_WARN("Closing Application...");
	return 0;
}