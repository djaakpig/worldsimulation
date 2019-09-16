#include "Controller.h"


class ServerController : public Controller
{
private:
	RemoteSessionComponentPtr _remoteSession;

public:
	ServerController()
	{
		SetInput(std::make_shared<RemoteInputComponent>());
	}

	virtual ~ServerController()
	{
	}

	void SetRemoteSession(const RemoteSessionComponentPtr session)
	{
		_remoteSession = session;
	}

	virtual void Update(const ClockRep delta)
	{
	}
};
