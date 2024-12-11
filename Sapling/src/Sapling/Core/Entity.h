#pragma once

#include "Sapling/Core/Base.h"

namespace Sapling
{

	class Entity
	{
	public:
		Entity() = default;
		virtual ~Entity() = default;

		virtual void OnUpdate() {}

	private:
		std::string _name;
		
	};

}