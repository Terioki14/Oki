#include <Oki.h>

class ExampleLayer : public Oki::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void onUpdate() override
	{
		OKI_INFO("ExampleLayer::Update");
	}

	void onEvent(Oki::Event& event) override
	{
		OKI_TRACE("{0}", event);
	}
};

class Sandbox : public Oki::Application
{
public:
	Sandbox() 
	{
		pushLayer(new ExampleLayer);
		pushOverlay(new Oki::ImGuiLayer());
	}

	~Sandbox() 
	{

	}
};

Oki::Application* Oki::createApplication() 
{
	return new Sandbox;
}