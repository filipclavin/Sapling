#pragma once

#include "Sapling/Core/Base.h"

namespace Sapling
{

	class SAPLING_API Mesh
	{
	public:
		Mesh() = default;
		virtual ~Mesh() = default;

		static Mesh Cube();

		virtual void OnUpdate() {}
		
	private:
		

	};
}