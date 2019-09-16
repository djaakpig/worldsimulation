#include "TypeDefine.hxx"


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

	void Update(const ClockRep delta)
	{
		_movement->Update(delta);
	}
};
