#pragma once

#ifdef OKI_PLATFORM_WINDOWS

extern Oki::Application* Oki::createApplication();

int main(int argc, char** argv) {
	printf("Oki Engine\n");
	auto app = Oki::createApplication();
	app->run();
	delete app;
}

#endif