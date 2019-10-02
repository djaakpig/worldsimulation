#pragma once
#include "Actors/PtrDefine.h"


class Cell final
{
private:
	ActorList _actors;

public:
	Cell()
	{
	}

	~Cell()
	{
	}

	bool Create()
	{
		return true;
	}

	void Destroy()
	{
	}
};
