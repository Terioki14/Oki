#pragma once

#include "Core.h"

namespace Oki {

	class OKI_API Application
	{
	public:
		Application();
		virtual ~Application();

		int run();
	};

	// To be defined in CLIENT
	Application* createApplication();
}