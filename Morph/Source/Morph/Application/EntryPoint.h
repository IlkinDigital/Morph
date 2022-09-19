#pragma once

#include "Application.h"

extern Morph::Application* CreateApplication();

int main()
{
	Morph::Application* app = CreateApplication();

	app->Run();

	delete app;

	return 0;
}