#pragma once

#ifdef SP_PLATFORM_WINDOWS

extern Sapling::Application* Sapling::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Sapling::CreateApplication();
	app->Run();
	delete app;
}

#endif
