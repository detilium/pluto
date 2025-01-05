#pragma once

#include "Core.h"

namespace Pluto
{
	class PLUTO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client.
	Application* CreateApplication();
}