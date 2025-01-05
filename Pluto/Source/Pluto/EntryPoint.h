#pragma once

#ifdef PLUTO_PLATFORM_WINDOWS

extern Pluto::Application* Pluto::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Pluto::CreateApplication();
	app->Run();
	delete app;
}

#endif