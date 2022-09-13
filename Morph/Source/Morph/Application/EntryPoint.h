#pragma once

#include "Application.h"

extern Morph::Application* Morph::CreateApplication();

int main()
{
	Morph::Application* app = Morph::CreateApplication();

	app->Run();

	delete app;

	return 0;
}