#pragma once

template<typename T>
class Point final
{
private:
	T _x;
	T _y;

public:
	#pragma region Getters
	T GetX() const
	{
		return _x;
	}

	T GetY() const
	{
		return _y;
	}
	#pragma endregion

	#pragma region Setters
	void SetX(const T x)
	{
		_x = x;
	}

	void SetY(const T y)
	{
		_y = y;
	}
	#pragma endregion
};
