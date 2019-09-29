#include "Component.h"


class RemoteInputComponent final : public InputComponent
{
private:
	RemoteSessionComponentPtr _remoteSession;

public:
	RemoteInputComponent()
	{
	}

	virtual ~RemoteInputComponent()
	{
	}

	virtual void Update(const ClockRep delta) override
	{
	}

	#pragma region Setters
	void SetRemoteSession(const RemoteSessionComponentPtr session)
	{
		_remoteSession = session;
	}
	#pragma endregion
};
