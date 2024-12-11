#pragma once

#include "Sapling/Core/Base.h"
#include "Sapling/Core/Layer.h"

#include <vector>

namespace Sapling
{
	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return _layers.begin(); }
		std::vector<Layer*>::iterator end() { return _layers.end(); }

	private:
		std::vector<Layer*> _layers;
		unsigned int _layerInsertIndex = 0;
	};
}
