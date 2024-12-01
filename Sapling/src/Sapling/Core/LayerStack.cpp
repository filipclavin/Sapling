#include "sappch.h"
#include "LayerStack.h"

namespace Sapling
{
	LayerStack::LayerStack()
	{
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : _layers)
		{
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		_layers.emplace(_layers.begin() + _layerInsertIndex, layer);
		_layerInsertIndex++;
	}

	/**
	* This function does not delete the layer, it just removes it from the stack.
	* It is the responsibility of the user to delete the layer or push it back onto the stack later.
	*/
	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(_layers.begin(), _layers.end(), layer);
		if (it != _layers.end())
		{
			_layers.erase(it);
			_layerInsertIndex--;
		}
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		_layers.emplace_back(overlay);
	}

	/**
	* This function does not delete the overlay, it just removes it from the stack.
	* It is the responsibility of the user to delete the overlay or push it back onto the stack later.
	*/
	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(_layers.begin(), _layers.end(), overlay);
		if (it != _layers.end())
		{
			_layers.erase(it);
		}
	}
}