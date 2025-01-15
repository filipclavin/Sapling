#pragma once

namespace Sapling
{
	class DeltaTime
	{
	public:
		DeltaTime(float time = 0.0f)
			: _time(time) {}

		inline float GetMilliseconds() const { return _time; }
		inline float GetSeconds() const { return _time / 1000.0f; }

		inline operator float() const { return _time; }

	private:
		float _time;
	};
}