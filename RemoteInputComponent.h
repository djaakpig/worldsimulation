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

	void SetRemoteSession(const RemoteSessionComponentPtr session)
	{
		_remoteSession = session;
	}

	virtual void Update(const ClockRep delta) override
	{
	}
};
