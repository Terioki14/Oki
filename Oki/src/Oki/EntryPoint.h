#pragma once

#ifdef OKI_PLATFORM_WINDOWS

extern Oki::Application* Oki::createApplication();

int main(int argc, char** argv) {
	
	Oki::Log::init();
	OKI_CORE_WARN("Initialized Log!");
	int a = 5;
	OKI_INFO("Hello! Var={0}", a);

	auto app = Oki::createApplication();
	app->run();
	delete app;
}

#endif