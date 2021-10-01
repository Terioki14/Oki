#pragma once

#include "Oki/Layer.h"
#include "Oki/Events/ApplicationEvent.h"
#include "Oki/Events/KeyEvent.h"
#include "Oki/Events/MouseEvent.h"

namespace Oki {

	class OKI_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void onAttach();
		void onDetach();
		void onUpdate();
		void onEvent(Event& event);
	private:
		bool onMouseMoved(MouseMovedEvent& e);
		bool onMouseScrolled(MouseScrolledEvent& e);
		bool onMouseButtonPressed(MouseButtonPressedEvent& e);
		bool onMouseButtonReleased(MouseButtonReleasedEvent& e);
		bool onKeyPressed(KeyPressedEvent& e);
		bool onKeyReleased(KeyReleasedEvent& e);
		bool onKeyTyped(KeyTypedEvent& e);
		bool onWindowResize(WindowResizeEvent& e);

		float m_Time = 0.0f;
	};

}