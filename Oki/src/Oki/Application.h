#pragma once

#include "Core.h"

#include "Window.h"
#include "LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace Oki {

	class OKI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

		void onEvent(Event& e);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);

		inline Window& getWindow() { return *m_Window; }

		inline static Application& get() { return *s_Instance; }
	private:
		bool onWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* createApplication();

}