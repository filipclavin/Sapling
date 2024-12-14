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

	}

	void OnEvent(Sapling::Event& event) override
	{
		if (event.GetEventType() == Sapling::EventType::CharTyped)
		{
			Sapling::CharTypedEvent& e = (Sapling::CharTypedEvent&)event;
			
			std::cout << e << std::endl;
		}
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