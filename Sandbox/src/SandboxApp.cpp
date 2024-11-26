#include <Sapling.h>

class Sandbox : public Sapling::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
		
	}

};

Sapling::Application* Sapling::CreateApplication()
{
	return new Sandbox();
}