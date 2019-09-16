#include "Component.h"


class UserInputComponent final : public InputComponent
{
public:
	UserInputComponent()
	{
	}

	virtual ~UserInputComponent()
	{
	}

	virtual void Update(const ClockRep delta) override
	{
	}
};
