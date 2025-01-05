#include <Pluto.h>

class Sandbox : public Pluto::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Pluto::Application* Pluto::CreateApplication()
{
	return new Sandbox();
}