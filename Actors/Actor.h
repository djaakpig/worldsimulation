#include "Core/TypeDefine.h"
#include "Components/PtrDefine.h"
#include "Components/MovementComponent.h"


class Actor
{
private:
	MovementComponentPtr _movement;

public:
	Actor()
	{
		_movement = MovementComponentPtr();
	}

	virtual ~Actor()
	{
	}

	virtual bool Create()
	{
		return true;
	}

	virtual void Destroy()
	{
	}

	virtual void Update(const ClockRep delta)
	{
		_movement->Update(delta);
	}
};
