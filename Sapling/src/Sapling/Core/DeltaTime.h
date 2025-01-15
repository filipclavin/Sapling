#pragma once

namespace Sapling
{
	class DeltaTime
	{
	public:
		DeltaTime(float time = 0.0f)
			: _time(time) {}

		float GetMilliseconds() const { return _time; }
		float GetSeconds() const { return _time / 1000.0f; }

		operator float() const { return _time; }

	private:
		float _time;
	};
}