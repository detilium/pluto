#pragma once

#ifdef PLUTO_PLATFORM_WINDOWS

extern Pluto::Application* Pluto::CreateApplication();

int main(int argc, char** argv)
{
	Pluto::Log::Init();
	PLUTO_CORE_WARN("Initialized log!");
	int a = 10;
	PLUTO_INFO("VARIABLE {0}!", a);

	auto app = Pluto::CreateApplication();
	app->Run();
	delete app;
}

#endif