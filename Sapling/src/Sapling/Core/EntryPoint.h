#pragma once

#ifdef WIN32

extern Sapling::Application* Sapling::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Sapling::CreateApplication();
	app->Run();
	delete app;
}

#endif
