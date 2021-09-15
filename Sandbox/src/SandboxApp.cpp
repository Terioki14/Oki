#include <Oki.h>

class Sandbox : public Oki::Application
{
public:
	Sandbox() {

	}

	~Sandbox() {

	}

};

Oki::Application* Oki::createApplication() {
	return new Sandbox;
}