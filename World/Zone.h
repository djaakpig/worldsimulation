#pragma once
#include <vector>
#include "Core/Point.h"
#include "Core/Shape.h"
#include "PtrDefine.h"

#include "Cell.h"


class Zone final
{
private:
	Point32i _start;
	Rectangle32i _size;
	Rectangle32i _numCells;
	std::vector<CellPtr> _cells;

public:
	Zone(
		const Point32i& start,
		const Rectangle32i& size,
		const Rectangle32i& numCells) :
		_start(start), _size(size), _numCells(numCells)
	{
	}

	~Zone()
	{
	}

	bool Create()
	{
		_cells.resize(_numCells.GetWidth() * _numCells.GetHeight());
		return true;
	}

	void Destroy()
	{
		for(auto& cell : _cells)
		{
			cell->Destroy();
		}
		_cells.clear();
	}

	bool Spawn(const ActorPtr& actor)
	{
		return true;
	}
};
