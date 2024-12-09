#pragma once

#include "Sapling/Core/Layer.h"
#include <Sapling/Events/MouseEvent.h>
#include <Sapling/Events/ApplicationEvent.h>
#include <Sapling/Events/KeyboardEvent.h>

namespace Sapling {
	class SAPLING_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender();

		void Begin();
		void End();

	private:
		bool _blockEvents = true;
		float _time = 0.0f;
	};
}