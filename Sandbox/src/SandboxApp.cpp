#include <Sapling.h>
#include <imgui.h>

class ExampleLayer : public Sapling::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//printf("ExampleLayer::Update\n");
	}

	void OnEvent(Sapling::Event& event) override
	{
		std::cout << "ExampleLayer::" << event << std::endl;
	}

	void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}
};

class Sandbox : public Sapling::Application
{
public:
	Sandbox()
	{
		std::cout << "Sandbox created" << std::endl;
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
		
	}

};

Sapling::Application* Sapling::CreateApplication()
{
	return new Sandbox();
}