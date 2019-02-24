#pragma once
#include <stdint.h>

template<typename T>
class Point final
{
private:
	T _x = 0;
	T _y = 0;
public:
	Point() = default;
	Point(const T x, const T y):
	_x(x), _y(y)
	{
	}
	T GetX() const
	{
		return _x;
	}
	T GetY() const
	{
		return _y;
	}
	void SetX(const T x)
	{
		_x = x;
	}
	void SetY(const T y)
	{
		_y = y;
	}
};

template<typename T>
class Rectangle final
{
private:
	T _width = 0;
	T _height = 0;
public:
	Rectangle() = default;
	Rectangle(const T width, const T height):
	_width(width), _height(height)
	{
	}
	T GetWidth() const
	{
		return _width;
	}
	T GetHeight() const
	{
		return _height;
	}
	void SetWidth(const T width)
	{
		_width = width;
	}
	void SetHeight(const T height)
	{
		_height = height;
	}
};
using Point32i = Point<int32_t>;
using Rectangle32i = Rectangle<int32_t>;
