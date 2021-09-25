#include "okipch.h"
#include "Application.h"

#include "Oki/Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace Oki 
{

	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::create());
	}

	Application::~Application() 
	{
	}

	void Application::run() 
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->onUpdate();
		}
	}

}