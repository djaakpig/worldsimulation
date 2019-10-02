#pragma once
#include <stdint.h>


template<typename T>
class Rectangle final
{
private:
	T _width = 0;
	T _height = 0;
	T _depth = 0;

public:
	Rectangle()
	{
	}

	Rectangle(const T width, const T height, const T depth) :
		_width(width), _height(height), _depth(depth)
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

	T GetDepth() const
	{
		return _depth;
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

	void SetDepth(const T depth)
	{
		_depth = depth;
	}
	#pragma endregion
};
using Rectangle32i = Rectangle<int32_t>;
