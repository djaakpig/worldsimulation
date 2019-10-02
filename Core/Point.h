#pragma once
#include <stdint.h>


template<typename T>
class Point final
{
private:
	T _x;
	T _y;
	T _z;

public:
	Point(const T x, const T y, const T z) :
		_x(x), _y(y), _z(z)
	{
	}

	#pragma region Getters
	T GetX() const
	{
		return _x;
	}

	T GetY() const
	{
		return _y;
	}
	T GetZ() const
	{
		return _z;
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

	void SetZ(const T z)
	{
		_z = z;
	}
	#pragma endregion
};
using Point32i = Point<int32_t>;
