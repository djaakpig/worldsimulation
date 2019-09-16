#include "Component.h"


class MovementComponent final : public Component
{
public:
	MovementComponent()
	{
	}

	virtual ~MovementComponent()
	{
	}

	virtual void Update(const ClockRep delta) override
	{
	}
};
