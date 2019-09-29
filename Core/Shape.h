#pragma once
#include <stdint.h>


template<typename T>
class Point final
{
private:
	T _x = 0;
	T _y = 0;

public:
	Point()
	{
	}

	Point(const T x, const T y) :
		_x(x), _y(y)
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


template<typename T>
class Rectangle final
{
private:
	T _width = 0;
	T _height = 0;

public:
	Rectangle()
	{
	}

	Rectangle(const T width, const T height) :
		_width(width), _height(height)
	{
	}

	#pragma region Getters
	T GetWidth() const
	{
		return _width;
	}

	T GetHeight() const
	{
		return _height;
	}
	#pragma endregion

	#pragma region Setters
	void SetWidth(const T width)
	{
		_width = width;
	}

	void SetHeight(const T height)
	{
		_height = height;
	}
	#pragma endregion
};
using Point32i = Point<int32_t>;
using Rectangle32i = Rectangle<int32_t>;
