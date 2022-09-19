#include "Morph/Application/EntryPoint.h"

using namespace Morph;

class MorphApp : public Application
{
public:
	MorphApp(const std::string& name)
		: Application(name) {}
};

Application* CreateApplication()
{
	return new MorphApp("Morph Application");
}