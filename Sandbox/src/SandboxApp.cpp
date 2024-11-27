#include <cstdio>
#include <Sapling.h>

class Sandbox : public Sapling::Application
{
public:
	Sandbox()
	{
		printf("SandboxApp started!");
	}

	~Sandbox()
	{
		
	}

};

Sapling::Application* Sapling::CreateApplication()
{
	return new Sandbox();
}