#pragma once

#include "Sapling/Events/Event.h"
#include "Sapling/Core/DeltaTime.h"

namespace Sapling
{
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(DeltaTime deltaTime) {}
		virtual void OnEvent(Event& event) {}
		virtual void OnImGuiRender() {}

		inline const std::string& GetName() const { return _debugName; }

	protected:
		std::string _debugName;
	};

}
